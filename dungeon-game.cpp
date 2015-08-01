class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.size() == 0) return 0;
        int m = dungeon.size(), n = dungeon[0].size();
        vector<int> dp(n+1, INT_MAX);
        dp[n - 1] = 1;
        for (int i = m-1; i >= 0; --i) {
            for (int j = n-1; j >= 0; --j) {
                int k = min(dp[j], dp[j+1]) - dungeon[i][j];
                dp[j] = k > 0 ? k : 1;
            }
        }
        return dp[0];
    }
};