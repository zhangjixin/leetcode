class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool row[m], col[n];
        memset(row, false, sizeof(row));
        memset(col, false, sizeof(col));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    row[i] = true;
                    col[j] = true;;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            if (row[i]) {
                for (int j = 0; j < n; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j = 0; j < n; ++j) {
            if (col[j]) {
                for (int i = 0; i < m; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        bool row0(false), col0(false);
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!matrix[i][j]) {
                    if (!i) row0 = true;
                    if (!j) col0 = true;
                    matrix[i][0] = 0, matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; ++i) {
            if (!matrix[i][0]) {
                int j = 1;
                while (j < n) matrix[i][j++] = 0;
            }
        }
        for (int i = 1; i < n; ++i) {
            if (!matrix[0][i]) {
                int j = 1;
                while (j < m) matrix[j++][i] = 0;
            }
        }
        if (row0) {
            int i = 0;
            while (i < n) matrix[0][i++] = 0;
        }
        if (col0) {
            int i = 0;
            while (i < m) matrix[i++][0] = 0;
        }
    }
};