class Solution {
public:
    int numDistinct(string S, string T) {
        int lenT(T.size()), lenS(S.size()), k(1);
        if (lenS < lenT) return 0;
        vector<vector<int> > dp(2, vector<int>(lenS + 1, 0));
        fill(dp[0].begin(), dp[0].end(), 1);
        for (int i = 1; i <= lenT; ++i) {
            for (int j = i; j <= lenS; ++j) {
                dp[k][j] = dp[k][j-1];
                if (S[j-1] == T[i-1]) {
                    dp[k][j] += dp[k^1][j-1];
                }
            }
            k ^= 1;
            fill(dp[k].begin(), dp[k].end(), 0);
        }
        return dp[k^1][lenS];
    }
};
