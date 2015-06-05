class Solution {
public:
    string shortestPalindrome(string s) {
        int len = s.size();
        if (len <= 1) return s;
        vector<int> Next(len, 0);
        kmp_next(s, Next);
        int id = kmp(s, Next);
        stringstream sm;
        for (int i = len - 1; i > id; --i) {
            sm << s[i];
        }
        return sm.str() + s;
    }
    int kmp(const string &s, const vector<int> &Next) {
        int len = s.size(), k = -1, ret = -1;
        for (int i = len-1; i >= 0; --i) {
            while (k != -1 && s[i] != s[k+1]) {
                ret -= k - Next[k];
                k = Next[k];
            }
            if (s[i] == s[k+1]) {
                if (ret == -1) ret = i;
                ++k;
                if (i - k <= 2) 
                    return ret;
            }
            else {
                ret = -1;
            }
        }
        return ret;
    }
    void kmp_next(const string &s, vector<int> &Next) {
        int len = s.size(), k = Next[0] = -1;
        for (int i = 1; i < len; ++i) {
            while (k != -1 && s[k+1] != s[i]) k = Next[k];
            if (s[i] == s[k+1]) k = k + 1;
            Next[i] = k;
        }
    }
};