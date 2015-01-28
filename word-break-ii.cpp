class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int len = s.size();
        vector<bool> vec(len, false);
        for (int i = 0; i < len; ++i) {
            if (dict.find(s.substr(0, i+1)) != dict.end()) {
                vec[i] = true;
                continue;
            }
            for(int j = 0; j < i; ++j) {
                if (vec[j]) {
                    if (dict.find(s.substr(j+1, i-j)) != dict.end()) {
                        vec[i] = true;
                        break;
                    }
                }
            }
        }
        doit(len-1, s, vec, dict);
        return ans;
    }
private:
    vector<string> v, ans;
    void doit(int k, const string &s, const vector<bool> &vec, const unordered_set<string> &dict) {
        string str;
        if (dict.find(str = s.substr(0,k+1)) != dict.end()) {
            for (int i = v.size()-1; i >= 0; --i) {
                str += " "+v[i];
            }
            ans.push_back(str);
        }
        for (int i = 0; i < k; ++i) {
            if (vec[i] && dict.find(str=s.substr(i+1,k-i)) != dict.end()) {
                v.push_back(str);
                doit(i, s, vec, dict);
                v.pop_back();
            }
        }
    }
};
