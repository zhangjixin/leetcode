class Solution {
public:
    int maxProduct(int A[], int n) {
        int ans(A[0]), n_num(0), p_num(0);
        A[0] >= 0 ? p_num = A[0] : n_num = A[0];
        for (int i = 1; i < n; ++i) {
            if (A[i] == 0) {
                n_num = 0, p_num = 0;
                ans = max(0, ans);
            }
            else if(A[i] > 0) {
                p_num = p_num == 0 ? A[i] : p_num * A[i];
                n_num = n_num == 0 ? 0 : n_num * A[i];
                if (p_num != 0) ans = max(p_num, ans);
            }
            else {
                int tmp = p_num;
                p_num = n_num * A[i];
                n_num = tmp == 0 ? A[i] : tmp * A[i];
                if (p_num != 0) ans = max(p_num, ans);
                if (n_num != 0) ans = max(n_num, ans);
            }
        }
        return ans;
    }
};
