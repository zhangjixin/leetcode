class Solution {
public:
    int trap(int A[], int n) {
        if (n <= 2) return 0;
        int ans = 0, lmax = A[0], rmax = A[n-1], i = 0, j = n - 1;
        while (i <= j) {
            if (lmax < rmax) {
                if (A[i] > lmax) {
                    lmax = A[i++];
                } else {
                    ans += lmax - A[i++];
                }
            }
            else {
                if (A[j] > rmax) {
                    rmax = A[j--];
                } else {
                    ans += rmax - A[j--];
                }
            }
        }
        return ans;
    }
};
