class Solution {
public:
    int calculate(string s) {
        stack<int> val;
        int sum = 0, cnt = 0, sign = 1, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                cnt = cnt * 10 + (s[i] - '0');
            }
            else if (s[i] == '*' || s[i] == '/') {
                if (sign > 1) {
                    sum = sign == 2 ? sum * cnt : sum / cnt;
                }
                else {
                    val.push(sum);
                    val.push(sign);
                    sum = cnt;
                }
                sign = s[i] == '*' ? 2 : 3;
                cnt = 0;
            }
            else if (s[i] == '+' || s[i] == '-') {
                if (sign > 1) {
                    sum = sign == 2 ? sum * cnt : sum / cnt;
                    while (!val.empty()) {
                        sum *= val.top();
                        val.pop();
                        sum += val.top();
                        val.pop();
                    }
                }
                else {
                    sum += cnt * sign;
                }
                cnt = 0;
                sign = s[i] == '+' ? 1 : -1;
            }
        }
        if (sign > 1) {
            sum = sign == 2 ? sum * cnt : sum / cnt;
        }
        else if (cnt != 0) {
            sum += cnt * sign;
        }
        while (!val.empty()) {
            sum *= val.top();
            val.pop();
            sum += val.top();
            val.pop();
        }
        return sum;
    }
};


class Solution {
public:
    int calculate(string s) {
        stack<int> val;
        int cnt = 0, sum = 0, sign = 1, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                cnt = cnt * 10 + (s[i] - '0');
            }
            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || i == n-1) {
                if (sign > 1) {
                    cnt = sign == 2 ? val.top() * cnt : val.top() / cnt;
                    val.pop();
                    val.push(cnt);
                }
                else {
                    val.push(cnt * sign);
                }
                cnt = 0;
                if (s[i] == '+') sign = 1;
                else if (s[i] == '-') sign = -1;
                else if (s[i] == '*') sign = 2;
                else sign = 3;
            }
        }
        while (!val.empty()) {
            sum += val.top();
            val.pop();
        }
        return sum;
    }
};