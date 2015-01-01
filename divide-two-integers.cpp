class Solution {
public:
    int divide(int dividend, int divisor) {
        int flag = 1, mypow[30];
        long long m = dividend, n = divisor, ans = 0;
        m <= 0 ? m =-m, flag*= -1: m;
        n <= 0 ? n =-n, flag*= -1: n;
        for(int i = 0; i < 30; ++i) mypow[i]  = 30 - i;
        while( m >= n ) {
            long long p = n, cnt = 1;
            for(int i = 0; i < 30; ) {
                if((p << mypow[i]) < m) {
                    p <<= mypow[i]; cnt <<= mypow[i];
                }else{
                    ++i;
                }
            }
            ans += cnt;
            m -= p;
        }
        ans *= flag;
        if(ans >= 0)
            return ans == (int) ans ? ans : INT_MAX;
        else
            return ans == (int) ans ? ans : INT_MIN;
    }
};