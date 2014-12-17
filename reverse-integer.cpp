class Solution {
public:
    int reverse(int x) {
        int ans = 0, tmp =0;
        while(x) {
            tmp = ans;
            ans = ans * 10 + x%10;
            if((ans - x%10)/10 != tmp)
                return 0;
            x /= 10;
        }
        return ans;
    }
};