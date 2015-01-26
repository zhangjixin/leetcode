class Solution {
public:
    int uniquePaths(int m, int n) {
        int k = m + n - 2, h = m > n ? n - 1 : m - 1, cnt = 0, len = h;
        long long ans = 1;
        while (cnt < len) {
            ans *= k - cnt;
            while (ans % h == 0 && h > 1) {
                ans /= h--;
            }
            ++cnt;
        }
        return ans;
    }
};
/*
class Solution {
public:
    int uniquePaths(int m, int n) {
        int arry[m][n] = {1}, i = 1, j = 1;
        while (i < m || i < n) {
            if (i < m) arry[i][0] = 1;
            if (i < n) arry[0][i] = 1;
            ++i;
        }
        for (i = 1; i < m; ++i) 
            for (j = 1; j < n; ++j)
                arry[i][j] = arry[i-1][j] + arry[i][j-1];
        return arry[m-1][n-1];
    }
};
*/
