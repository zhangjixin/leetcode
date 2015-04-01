class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        int len = tokens.size(), a, b;
        stack<int> mystack;
        for (int i = 0; i < len; ++i) {
            if ((tokens[i][0] >= '0' && tokens[i][0] <= '9') || tokens[i].size() > 1) {
                mystack.push(atoi(tokens[i].c_str()));
                continue;
            }
            a = mystack.top(), mystack.pop();
            b = mystack.top(), mystack.pop();
            switch(tokens[i][0]) {
                case '+' : {
                    mystack.push(a+b);
                    break;
                }
                case '-' : {
                    mystack.push(b-a);
                    break;
                }
                case '*' : {
                    mystack.push(a*b);
                    break;
                }
                case '/' : {
                    mystack.push(b/a);
                    break;
                }
            }
        }
        return mystack.top();
    }
};
