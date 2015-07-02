class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
        if (matrix.size() < 1) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int> > vec(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
            vec[i + 1][j + 1] = matrix[i][j] == '1' ? 1 : 0;
            vec[i + 1][j + 1] += vec[i][j+1] + vec[i+1][j] - vec[i][j];
        }

        int ans = vec[m][n] > 0 ? 1 : 0, k = 0, area = 0;

        for (int i = ans + 1; i <= m; ++i)
        for (int j = ans + 1; j <= n ; ++j) {
            k = ans + 1;
            area = k * k;
            if (vec[i][j] - vec[i-k][j] - vec[i][j - k] + vec[i-k][j-k] == area) {
                ans = k;
                break;
            }
        }
        return ans * ans;
    }
};
