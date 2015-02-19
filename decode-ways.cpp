class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0 || s[0] == '0') return 0;
        int len(s.size());
        vector<int> vec(len, 0);
        vec[0] = 1;
        for (int i = 1; i < len; ++i) {
            if (s[i] != '0')
                vec[i] = vec[i-1];
            else if (s[i-1] > '3' || s[i-1] == '0')
                return 0;
            if (s[i-1] != '0' && ((s[i-1]-'0') * 10 + (s[i] - '0')) <= 26)
                vec[i] += i >= 2 ? vec[i-2] : 1;
        }
        return vec[len-1];
    }
};

class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0 || s[0] == '0') return 0;
        int len(s.size());
        vector<int> vec(len, 0);
        vec[0] = 1;
        for (int i = 1; i < len; ++i) {
            if (s[i] == '0') {
                if (s[i-1] == '0') 
                    return 0;
                if (s[i-1] < '3') {
                    vec[i] = (i >= 2 ? vec[i - 2] : 1);
                } else {
                    return 0;
                }
            } else {
                if (s[i-1] == '0') {
                    vec[i] = vec[i-1];
                } else {
                    int tmp = cal(s[i-1] - '0', s[i] - '0');
                    if (i >= 2)
                        vec[i] = tmp == 2 ? vec[i-2] + vec[i-1] : vec[i-1];
                    else 
                        vec[i] = tmp;
                }
            }
        }
        return vec[len-1];
    }
private:
    int cal(int a, int b) {
        a = a * 10 + b;
        if (a >= 11 && a <= 26){
            return 2;
        }
        return 1;
    }
};