class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int x(0), y(0), i(0), j(n * m - 1), k(0);
        while (i <= j) {
            k = (i + j) >> 1;
            x = k / n, y = k % n;
            if (matrix[x][y] == target) return true;
            if (matrix[x][y] > target) j = k - 1;
            else i = k + 1;
        }
        return false;
    }
};