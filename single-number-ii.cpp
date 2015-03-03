class Solution {
public:
    int singleNumber(int A[], int n) {
        int bitarry[32] = {0}, ans(0);
        for (int i = 0; i < n; ++i) {
            int tmp = A[i];
            for (int j = 0; j < 32 && tmp; ++j) {
                bitarry[j] += (tmp & 1);
                tmp >>= 1;
            }
        }
        for (int i = 0; i < 32; ++i) {
            if (bitarry[i] % 3) {
                ans |= (1 << i);
            }
        }
        return ans;
    }
};