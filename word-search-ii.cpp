class TrieNode {
public:
    TrieNode() {
        for (int i = 0; i < 26; ++i) {
            val[i] = NULL;
        }
        flag = false;
    }
    bool flag;
    TrieNode *val[26];
};
class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    void insert(string s) {
        int len = s.size();
        TrieNode *cur = root;
        for (int i = 0; i < len; ++i) {
            if (cur->val[s[i] - 'a'] == NULL) {
                cur->val[s[i] - 'a'] = new TrieNode();
            }
            cur = cur->val[s[i] - 'a'];
        }
        cur->flag = true;
    }
    bool search(string key) {
        int len = key.size();
        TrieNode *cur = root;
        for (int i = 0; i < len; ++i) {
            if (cur->val[key[i] - 'a'] == NULL)
                return false;
            cur = cur->val[key[i] - 'a'];
        }
        return cur->flag;
    }
    bool startsWith(string prefix) {
        int len = prefix.size();
        TrieNode *cur = root;
        for (int i = 0; i < len; ++i) {
            if (cur->val[prefix[i] - 'a'] == NULL)
                return false;
            cur = cur->val[prefix[i] - 'a'];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int len = words.size();
        for (int i = 0; i < len; ++i) {
            trie.insert(words[i]);
        }
        unordered_set<string> ret;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(board, i, j, m, n,"",ret);
            }
        }
        vector<string> ans(ret.begin(), ret.end());
        return ans;
    }
    void dfs(vector<vector<char>>& board, int i, int j, int m, int n, string str, unordered_set<string> &ret) {
        if (i < 0 || i >= m || j < 0 || j >= n) return;
        if (board[i][j] == 'A') return;
        str += board[i][j];
        if (!trie.startsWith(str)) return;
        if (trie.search(str)) {
            ret.insert(str);
        }
        char ch = board[i][j];
        board[i][j] = 'A';
        dfs(board, i-1, j, m, n, str, ret);
        dfs(board, i+1, j, m, n, str, ret);
        dfs(board, i, j-1, m, n, str, ret);
        dfs(board, i, j+1, m, n, str, ret);
        board[i][j] = ch;
    }
private:
    Trie trie;
};