class Solution {
public:
    int calculate(string s) {
        stack<char> operStack;
        stack<int> numStack;
        int ans = 0, n = s.size(), sum = 0;
        for (int i = 0; i < n; ++i) {
            sum = 0;
            if ((!(s[i] >= '0' && s[i] <= '9')) && s[i] != ')') {
                if (s[i] != ' ')
                    operStack.push(s[i]);
                continue;
            }
            if (s[i] == ')') {
                bool flag = false;
                while (operStack.top() != '(') {
                    flag = true;
                    int num = numStack.top(); 
                    numStack.pop();
                    sum = doCal(sum, num, operStack.top());
                    operStack.pop();
                }
                operStack.pop();
                if (flag) {
                    sum += numStack.top();
                    numStack.pop();
                    numStack.push(sum);
                }
                continue;
            }
            while (i < n && s[i] >= '0' && s[i] <= '9') {
                sum = sum * 10 + (s[i] - '0');
                ++i;
            }
            i -= 1;
            numStack.push(sum);
        }
        ans = 0;
        while (!operStack.empty()) {
            char ch = operStack.top();
            operStack.pop();
            if (ch == '+' || ch == '-') {
                int num = numStack.top();
                numStack.pop();
                ans = doCal(ans, num, ch);
            }
        }
        return ans + numStack.top();
    }
    int doCal(int a, int b, char ch) {
        if (ch == '+') 
            return a + b;
        return a - b;
    }
};


class Solution {
public:
    int calculate(string s) {
        stack<int> val;
        int n = s.size(), sum = 0, sign = 1, num = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + (s[i] - '0');
            }
            else if (s[i] == '+' || s[i] == '-') {
                sum += num * sign;
                num = 0;
                sign = s[i] == '+' ? 1 : -1;
            }
            else if (s[i] == '(') {
                val.push(sum);
                val.push(sign);
                sum = 0;
                sign = 1;
            }
            else if (s[i] == ')') {
                sum += num * sign;
                sum *= val.top();
                val.pop();
                sum += val.top();
                val.pop();
                num = 0;
            }
        }
        if (num != 0) 
            sum += num * sign;
        return sum;
    }
};