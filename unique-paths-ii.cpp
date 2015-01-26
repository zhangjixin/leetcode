class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    obstacleGrid[i][j] = 0;
                } else {
                    if (i == 0 || j == 0) {
                        if (i) obstacleGrid[i][j] = obstacleGrid[i-1][j];
                        else if (j) obstacleGrid[i][j] = obstacleGrid[i][j-1];
                        else obstacleGrid[i][j] = 1;
                    } else {
                        obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
                    }
                }
            }
        return obstacleGrid[m-1][n-1];
    } 
};
