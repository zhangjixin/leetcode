class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = strlen(s) - 1, ans(0);
        while (s[len] == ' ') --len;
        for (int i = len; i >= 0; --i) {
            if (s[i] == ' ') {
                return ans;
            }
            ++ans;
        }
        return ans;
    }
};
