class Solution {
public:
    bool isNumber(const char *s) {
        int len = strlen(s), i = 0;
        bool flagd = true, flage = true, num = false;
        while (i < len && s[i] == ' ') ++i;
        while (s[len-1] == ' ') --len;
        if (s[i] == '+' || s[i] == '-') ++i;
        for (; i < len; ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                num = true;
            }
            else if (s[i] == '.') {
                if (flagd && flage) flagd = false;
                else return false;
            }
            else if (s[i] == 'e') {
                if (flage && num) {
                    num = flage = false;
                } else {
                    return false;
                }
            }
            else if (s[i] == '+' || s[i] == '-'){
                if (s[i-1] != 'e' && s[i-1] != 'E') return false;
            } 
            else {
                return false;
            }
        }
        return num;
    }
};
