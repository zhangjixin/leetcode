class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans, vec(4, "");
        doit(0, 1, s, vec, ans);
        return ans;
    }
private:
    void doit(int i, int k, string s, vector<string> &vec, vector<string> &ans) {
        int a = 0, j = i, len = s.size();
        if (k == 4) {
            if (len - i > 3 || len - i <= 0) return;
            if (len - i > 1 && s[i] == '0') return;
            while (j < len) 
                a = a * 10 + (s[j++] - '0');
            if (a >= 0 && a <= 255) {
                vec[k-1] = s.substr(i);
                string ss(vec[0]);
                for (j = 1; j < 4; ++j) ss += "." + vec[j];
                ans.push_back(ss);
            }
            return;
        }
        while (j < len) {
            a = a * 10 + (s[j++] - '0');
            if (j - i > 1 && s[i] == '0') return;
            if (a >= 0 && a <= 255) {
                vec[k-1] = s.substr(i, j - i);
                doit(j, k + 1, s, vec, ans);
            } else {
                return;
            }
        }
        return;
    }
};