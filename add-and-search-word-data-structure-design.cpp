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
class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        int len = word.size();
        TrieNode *cur = root;
        for (int i = 0; i < len; ++i) {
            if (cur->val[word[i] - 'a'] == NULL) {
                cur->val[word[i] - 'a'] = new TrieNode();
            }
            cur = cur->val[word[i] - 'a'];
        }
        cur->flag = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return doSearch(word, 0, root);
    }
    bool doSearch(string word, int k, TrieNode *root) {
        if (k == word.size())
            return root && root->flag;
        if (root == NULL) 
            return false;
        if (word[k] == '.') {
            for (int i = 0; i < 26; ++i) {
                if (root->val[i] != NULL) {
                    if (doSearch(word, k+1, root->val[i]))
                        return true;
                }
            }
        } 
        else if (root->val[word[k] - 'a'] != NULL) {
            return doSearch(word, k + 1, root->val[word[k] - 'a']);
        }
        return false;
    }
private:
    TrieNode* root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");