class TrieNode {
public:
    // Initialize your data structure here.
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

    // Inserts a word into the trie.
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

    // Returns if the word is in the trie.
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

    // Returns if there is any word in the trie
    // that starts with the given prefix.
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