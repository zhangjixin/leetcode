class Solution {
public:
    int trap(int A[], int n) {
        if (n <= 2) return 0;
        int ans = 0, val, maxdex = (A[0] > A[1] ? 0 : 1);
        for (int i = maxdex + 1, j = 0; i < n; ++i) {
            if (A[i] > A[i-1]) {
                j = maxdex;
                val = min(A[maxdex], A[i]);
                while (j + 1 < i) {
                    if (val >= A[j+1]) {
                        ans += val - A[j+1];
                        A[j+1] = val; 
                    }
                    ++j;
                }
                if (A[i] >= A[maxdex]) maxdex = i;
            }
        }
        return ans;
    }
};
