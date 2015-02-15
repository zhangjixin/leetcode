class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.size() < 1) return 0;
        int m = matrix.size(), n = matrix[0].size(), ans = 0;
        vector<int> left(n, 0), right(n, n-1), h(n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0, dex = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    ++h[j];
                    left[j] = max(left[j], dex);
                }
                else {
                    h[j] = 0, left[j] = 0;
                    dex = j + 1;
                }
            }
            for (int j = n-1, dex = n-1; j >= 0; --j) {
                if (matrix[i][j] == '1') {
                    right[j] = min(right[j], dex);
                    ans = max(ans, h[j] * (right[j] - left[j] + 1));
                }
                else {
                    right[j] = n - 1;
                    dex = j - 1;
                }
            }
        }
        return ans;
    }
};