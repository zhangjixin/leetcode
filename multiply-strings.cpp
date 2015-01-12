class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size(), len2 = num2.size();
        char ans[len1 + len2 + 2];
        memset(ans, '0', sizeof(ans));
        int dex(0), n(len1 + len2 + 1), val;
        for (int i = len2 -1; i >= 0; --i) {
            dex = len2 - i - 1;
            for (int j = len1 - 1; j >= 0; --j, ++dex) {
                val = ans[dex] - '0' +  (num1[j] - '0') * (num2[i] - '0');
                ans[dex] = (val % 10) + '0';
                ans[dex + 1] +=   val  / 10;
            }
        }
        while (ans[n] == '0') --n;
        n = n < 0 ? 0 : n;
        string str = string(ans,n+1);
        reverse(str.begin(), str.end());
        return str;
    }
};
