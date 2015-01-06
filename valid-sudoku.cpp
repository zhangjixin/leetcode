class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int row[9] = {0}, col[9] = {0}, matrix[9] = {0}, flag[9] = {1};
        
        for(int i = 1; i < 9; ++i) flag[i] = (flag[i-1] << 1);
        
        for(int i = 0, k, h; i < 9; ++i ) {
            k = i/3 * 3;
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] != '.'){
                    h = board[i][j] - '0' - 1;
                    if( (row[i] | flag[h]) != row[i]) {
                        row[i] |= flag[h];
                    }else return false;
                    
                    if( (col[j] | flag[h]) != col[j]) {
                        col[j] |= flag[h];
                    }else return false;
                    
                    if( (matrix[k+j/3] | flag[h]) != matrix[k+j/3]) {
                        matrix[k+j/3] |= flag[h];
                    }else return false;
                }
            }
        }
        return true;
    }
};
