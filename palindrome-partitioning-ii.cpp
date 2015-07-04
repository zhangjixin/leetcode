class Solution {
public:
    int minCut(string s) {
        int len = s.size();
        vector<vector<bool>> flag(len, vector<bool>(len, false));
        vector<int> dp(len, 0);
        flag[0][0] = true;
        for (int i = 1; i < len; ++i){
            flag[i][i] = true;
            int minc = dp[i-1] + 1;
            for (int j = 0; j < i; ++j) {
                if (s[j] == s[i] && (j == i - 1 || flag[j+1][i-1])) {
                    flag[j][i] = true;
                    minc = j == 0 ? 0 : min(minc, dp[j-1] + 1);
                }
            }
            dp[i] = minc;
        }
        return dp[len-1];
    }
};

class Solution {
public:
    int minCut(string s) {
        int len = s.size();
        vector<int> dp(len + 1, 0);
        for (int i = 0; i <= len; ++i) dp[i] = i - 1;
        for (int i = 0; i < len; ++i) {
            for (int j = 0; i - j >= 0 && i + j < len && s[i -j] == s[i + j]; ++j)
                dp[i + j + 1] = min(dp[i + j + 1] , dp[i - j] + 1);
            for (int j = 1; i - j + 1 >= 0 && i + j < len && s[i-j+1] == s[i+j]; ++j)
                dp[i+j+1] = min(dp[i+j+1], dp[i-j+1] + 1);
        }
        return dp[len];
    }
};
