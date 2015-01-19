class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ans;
        if (matrix.size() == 0) return ans;
        int i, j, m = matrix.size(), n = matrix[0].size(), k = min(m, n);
        for (i = 0; i < (k+1) >> 1; ++i) {
            for (j = i; j < n-i; ++j) ans.push_back(matrix[i][j]);
            if (n - i - 1 >= 0) {
                for (j = i+1; j < m-i; ++j) ans.push_back(matrix[j][n-i-1]); 
            }
            if (m - i - 1 > i) {
                for (j = n- i - 2; j >= i; --j) ans.push_back(matrix[m-i-1][j]);
            }
            if (i < n - i - 1) {
                for (j = m - i - 2; j > i; --j) ans.push_back(matrix[j][i]);
            }
        }
        return ans;
    }
};
