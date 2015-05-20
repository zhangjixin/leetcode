class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;
        int ans = 0, m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vec(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '1' && !vec[i][j]) {
                dfs(grid, i, j, m, n, vec);
                ++ans;
            }
            else{
                vec[i][j] = true;
            }
        }
        return ans;
    }
private:
    bool do_check(int i, int j, int m, int n) {
        return (i >= 0 && i < m && j >= 0 && j < n);
    }
    void dfs(const vector<vector<char>>& grid, int i, int j, int m, int n, vector<vector<bool>> &vec) {
        vec[i][j] = true;
        for (int k = 0; k < 4; ++k) {
            int ii = i + mmap[k][0], jj = j + mmap[k][1];
            if (do_check(ii, jj, m, n) && !vec[ii][jj] && grid[ii][jj] == '1') {
                dfs(grid, ii, jj, m, n, vec);
            }
        }
    }
    int mmap[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}}; 
};