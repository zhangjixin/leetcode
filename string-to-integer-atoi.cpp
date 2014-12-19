class Solution {
public:
    int atoi(const char *str) {
        int flag = 1, i = 0;
        long long ans = 0;
        while(str[i] == ' ')
            ++i;
        if((str[i] == '+') || (str[i] == '-')){
            flag = (str[i] == '-')?-1:1;
            ++i;
        }
        while( (str[i] >= '0') && (str[i] <= '9')) {
            ans = ans * 10 + int(str[i] - '0');
            if( ans * flag >= INT_MAX) return INT_MAX;
            if(ans * flag <= INT_MIN) return INT_MIN;
            ++i;
        }
        return ans*flag;
    }
};