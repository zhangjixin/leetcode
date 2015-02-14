class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n < 3) return n;
        int len(1);
        bool flag(false);
        for (int i = 1; i < n; ++i) {
            if (A[i] != A[i-1]) {
                flag = false;
                A[len++] = A[i];
            }
            else if (!flag){
                flag = true;
                A[len++] = A[i];
            }
        }
        return len;
    }
};