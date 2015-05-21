class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (m == 0 || n == 0) return 0;
        if (m == n) return m;
        int bit = (1 << 30), ans = 0;
        while (bit) {
            if ((m & bit) != (n & bit))
                break;
            else if (m & bit)
                ans |= bit;
            bit >>= 1;
        }
        return ans;
    }
};