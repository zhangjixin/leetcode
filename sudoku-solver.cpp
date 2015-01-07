/* solution 1
class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        int row[9] = {0}, col[9] = {0}, matrix[9] = {0}, flag[9] = {1};
        vector<vector<int> > dex;
        for(int i = 1; i < 9; ++i) flag[i] = flag[i-1] << 1;
        
        for(int i = 0, k, h; i < 9; ++i ) {
            k = i / 3 * 3;
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] != '.') {
                    h = board[i][j] - '0' - 1;
                    row[i] |= flag[h], col[j] |= flag[h], matrix[k+j/3] |= flag[h];
                } else {
                    dex.push_back({i, j});
                    ++cnt;
                }
            }
        }
        
        doit(dex, row, col, matrix, flag, board, 0);
    }
    
private:
    int cnt = 0;
    bool doit(vector<vector<int> > &vec, int row[], int col[], int matrix[], int flag[], vector<vector<char> > &ans, int dex) {
        if(dex >= cnt) return true;
        int i = vec[dex][0], j = vec[dex][1], k = i / 3 * 3;
        for(int n = 0; n < 9; ++n) {
            if( ((row[i] | flag[n])!=row[i]) && ((col[j] | flag[n])!=col[j]) && ((matrix[k+j/3] | flag[n])!=matrix[k+j/3]) ) {
                row[i] |= flag[n], col[j] |= flag[n], matrix[k+j/3] |= flag[n];
                ans[i][j] = n + 1 + '0';
                if( doit(vec, row, col, matrix, flag, ans, dex+1) ) {
                    return true;
                }
                else {
                    row[i] &= (~flag[n]), col[j] &= (~flag[n]), matrix[k+j/3] &= (~flag[n]);
                }
            }
        }
        return false;
    }
};
*/
class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        
        for(int i = 1; i < 9; ++i) flag[i] = flag[i-1] << 1;
        
        for(int i = 0, k, h; i < 9; ++i ) {
            k = i / 3 * 3;
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] != '.') {
                    h = board[i][j] - '0' - 1;
                    row[i] |= flag[h], col[j] |= flag[h], matrix[k+j/3] |= flag[h];
                } else {
                    vec.push_back({i, j});
                    ++cnt;
                }
            }
        }
        
        doit(0, board);
    }
    
private:
    int row[9] = {0}, col[9] = {0}, matrix[9] = {0}, flag[9] = {1}, cnt = 0;
    vector<vector<int> > vec;
    
    bool doit(int dex, vector<vector<char> > &ans) {
        if(dex >= cnt) return true;
        int i = vec[dex][0], j = vec[dex][1], k = i / 3 * 3;
        for(int n = 0; n < 9; ++n) {
            if( ((row[i] | flag[n])!=row[i]) && ((col[j] | flag[n])!=col[j]) && ((matrix[k+j/3] | flag[n])!=matrix[k+j/3]) ) {
                row[i] |= flag[n], col[j] |= flag[n], matrix[k+j/3] |= flag[n];
                ans[i][j] = n + 1 + '0';
                if( doit(dex+1,ans) ) {
                    return true;
                }
                else {
                    row[i] &= (~flag[n]), col[j] &= (~flag[n]), matrix[k+j/3] &= (~flag[n]);
                    //ans[i][j] = '.';
                }
            }
        }
        return false;
    }
};
