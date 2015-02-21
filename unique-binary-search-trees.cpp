class Solution {
public:
    int numTrees(int n) {
        if (n == 0) return 0;
        vector<int> vec(n+1, 0);
        int ans = 0;
        vec[0] = vec[1] = 1, vec[2] = 2, vec[3] = 5;
        for (int i = 4; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                vec[i] += vec[j - 1] * vec[i - j];
            }
        }
        return vec[n];
    }
};