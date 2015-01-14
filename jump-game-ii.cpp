class Solution {
public:
    int jump(int A[], int n) {
        int left(0), right(0), dex(0);
        for (int i = 1; i <= n - 1; ++i) {
            dex = right;
            while (left <= right) {
                dex = max(dex, left + A[left]);
                if (dex >= n-1) {
                    return i;
                }
                ++left;
            }
            right = dex;
        }
        return n - 1;
    }
};
