class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans(0);
        //uint32_t One(1), Zero(0);
        while (n != 0) {
            if (n&1) ++ans;
            n >>= 1;
        }
        return ans;
    }
};