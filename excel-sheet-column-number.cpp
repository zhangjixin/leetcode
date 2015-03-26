class Solution {
public:
    int titleToNumber(string s) {
        int len(s.size() - 1), ans(0);
        ans = s[len] - 'A' + 1;
        for (int i = len - 1; i >= 0; --i) {
            ans += pow(26, len - i) * (s[i] - 'A' + 1);
        }
        return ans;
    }
};