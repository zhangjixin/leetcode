class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int len = matrix.size(), dexi, dexj, val;
        for (int i = 0, I = len / 2; i < I; ++i) {
            for (int j = i, J = len - i - 1; j < J; ++j) {
                dexi = i, dexj = j, val = matrix[i][j];
                for (int k = 0; k < 4; ++k) {
                    swap(val, matrix[dexj][len - dexi - 1]);
                    swap(dexi, dexj);
                    dexj = len - dexj - 1;
                }
            }
        }
    }
};
