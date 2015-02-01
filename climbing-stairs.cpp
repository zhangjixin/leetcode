class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return n;
        vector<int> arry(n, 0);
        arry[0] = 1, arry[1] = 2;
        for (int i = 2; i < n; ++i) {
            arry[i] = arry[i-1] + arry[i-2];
        }
        return arry[n-1];
    }
};