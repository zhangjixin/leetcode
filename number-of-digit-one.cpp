class Solution {
public:
    int countDigitOne(int n) {
        int ret;
        int leftN = n, rightN = 0, curN = 0;
        for (int bit = 1; bit <= n; bit *= 10) {
            curN = leftN % 10;
            leftN /= 10;
            if (curN > 1) {
                ret += (leftN + 1) * bit;
            } 
            else if (curN == 1) {
                ret += leftN * bit;
                ret += rightN + 1;
            }
            else {
                ret += leftN * bit;
            }
            rightN = curN * bit + rightN;
        }
        return ret;
    }
};