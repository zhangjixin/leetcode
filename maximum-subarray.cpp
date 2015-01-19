class Solution {
public:
    int maxSubArray(int A[], int n) {
        int ans = A[0], val = 0;
        for (int i = 0; i < n; ++i) {
            val += A[i];
            if (val > ans) ans = val;
            if (val < 0) val = 0;
        }
        return ans;
    }
};
