class Solution {
public:
    double pow(double x, int n) {
        if (x == 1) return 1;
        if (x == -1) return n&1 ? -1 : 1;
        double ans = 1;
        bool flag = n < 0;
        long long m = abs((long long)n);
        while (m) {
            if (m&1) ans *= x;
            if (ans == 0 ) return ans; 
            x *= x;
            m >>= 1;
        }
        if (flag) return 1/ans;
        else return ans;
    }
};