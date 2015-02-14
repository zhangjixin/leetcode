class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool> > used(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    used[i][j] = true;
                    if (doit(i, j, 0, board, word, used)) 
                        return true;
                    used[i][j] = false;
                }
            }
        }
        return false;
    }
private:
    int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bool check_it(int i, int j, int m, int n) {
        return (i >= 0 && i < m && j >= 0 && j < n);
    }
    bool doit(int i, int j, int k, const vector<vector<char> > &board, const string &w, vector<vector<bool> > &used) {
        if (k == w.size() - 1) return true;
        int m = board.size(), n = board[0].size();
        for (int c = 0; c < 4; ++c) {
            if (check_it(i+d[c][0], j+d[c][1], m, n) && !used[i+d[c][0]][j+d[c][1]] && board[i+d[c][0]][j+d[c][1]] == w[k+1]) {
                used[i+d[c][0]][j+d[c][1]] = true;
                if (doit(i+d[c][0], j+d[c][1], k+1, board, w, used))
                    return true;
                used[i+d[c][0]][j+d[c][1]] = false;
            }
        }
        return false;
    }
};