class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int ai = m -1, bi = n - 1, k = m + n - 1;
        while (k >= 0) {
            if (ai == -1) {
                while (k >= 0) {
                    A[k--] = B[bi--];
                }
                return ;
            }
            if (bi == -1) {
                return ;
            }
            if (A[ai] >= B[bi]) {
                A[k--] = A[ai--];
            }
            else {
                A[k--] = B[bi--];
            }
        }
    }
};
