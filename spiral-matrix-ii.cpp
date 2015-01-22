class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> >ans(n, vector<int>(n, 0));
        for (int i = 0, j, leni = (n + 1) / 2, cnt = 1; i < leni; ++i) {
            for (j = i; j < n - i; ++j) {
                ans[i][j] = cnt++;
            }
            for (j = i + 1; j < n - i; ++j) {
                ans[j][n - i - 1] = cnt++;
            }
            for (j = n - i - 2; j >= i; --j) {
                ans[n - i - 1][j] = cnt++;
            }
            for (j = n - i - 2; j > i; --j) {
                ans[j][i] = cnt++;
            }
        }
        return ans;
    }
};
