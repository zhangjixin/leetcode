class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int len = s.size();
        vector<bool> vec(len, false);
        for (int i = 0; i < len; ++i) {
            vec[i] = (dict.find(s.substr(0, i + 1)) != dict.end());
            if (vec[i])
                continue;
            for (int j = 0; j < i; ++j) {
                if (vec[j]) {
                    vec[i] = (dict.find(s.substr(j+1, i-j)) != dict.end());
                    if (vec[i])
                        break;
                }
            }
        }
        return vec[len - 1];
    }
};
