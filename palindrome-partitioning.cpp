class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        vector<string> tmp;
        int len = s.size();
        vector<vector<bool>> flag(len, vector<bool>(len, false));
        for (int i = 0; i < len; ++i)
        for (int j = 0; j <= i; ++j) {
            flag[j][i] = doCheck(s, j, i);
        }
        findAns(s, 0, tmp, ret, flag);
        return ret;
    }
    void findAns(const string &s, const int idx, vector<string> &tmp, vector<vector<string>> &ret, const vector<vector<bool>> &flag) {
        int len = s.size();
        if (idx == len) {
            ret.push_back(tmp);
            return;
        }
        for (int i = idx; i < len; ++i) {
            if (flag[idx][i]) {
                tmp.push_back(s.substr(idx, i - idx + 1));
                findAns(s, i + 1, tmp, ret, flag);
                tmp.pop_back();
            }
        }
    }
    bool doCheck(const string &s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
};