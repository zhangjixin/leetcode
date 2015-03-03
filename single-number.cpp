class Solution {
public:
    int singleNumber(int A[], int n) {
        int ans = A[0], i = 0;
        while (++i < n) ans ^= A[i];
        return ans;
    }
};