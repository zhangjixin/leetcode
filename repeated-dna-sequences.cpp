#define decode(ch) ((ch - 'A' + 1) % 5)
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> umap;
        vector<string> ret;
        int i = 0, k = 0, n = s.size();
        if (n < 11) 
            return ret;
        for (i = 0; i < 9; ++i) {
            k = (k << 2) | decode(s[i]);
        }
        for(; i < n; ++i) {
            k = (k << 2) & 0xfffff | decode(s[i]);
            if (umap[k]++ == 1) {
                ret.push_back(s.substr(i-9, 10));
            }
        }
        return ret;
    }
};