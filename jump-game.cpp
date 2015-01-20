class Solution {
public:
    bool canJump(int A[], int n) {
        int val(0);
        for (int i = 0; i < n && i <= val; ++i) {
            val = max(val, i + A[i]);
            if (val >= n-1)
                return true;
        }
        return false;
    }
};
