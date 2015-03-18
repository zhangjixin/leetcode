class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if (board.size() < 1) return;
        int m = board.size(), n = board[0].size();
        queue<pair<int, int>> que;
        pair<int, int> dex;
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}, x, y;
        
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') {
                que.push(make_pair(i, 0));
                board[i][0] = '.';
            }
            if (board[i][n-1] == 'O') {
                que.push(make_pair(i, n-1));
                board[i][n-1] = '.';
            }
        }
        for (int i = 1; i < n - 1; ++i) {
            if (board[0][i] == 'O') {
                que.push(make_pair(0,i));
                board[0][i] = '.';
            }
            if (board[m-1][i] == 'O') {
                que.push(make_pair(m-1, i));
                board[m-1][i] = '.';
            }
        }
        while (!que.empty()) {
            dex = que.front();
            que.pop();
            for (int i = 0; i < 4; ++i) {
                x = dex.first + dir[i][0], y = dex.second + dir[i][1];
                if ((x >= 0 && x < m && y >= 0 && y < n) && board[x][y] == 'O') {
                    que.push(make_pair(x, y));
                    board[x][y] = '.';
                }
            }
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] = board[i][j] == '.' ? 'O'  : 'X';
            }
        }
    }
};
