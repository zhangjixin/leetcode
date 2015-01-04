class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> mystack;
        int ans = 0, dex = -1, cnt = 0;
        for(int i = 0; i < s.length(); ++i) {
            if(s[i] == '(') mystack.push(i);
            else if(s[i] ==')') {
                if(!mystack.empty()) {
                    mystack.pop();
                    cnt = (mystack.empty() ? i - dex : i - mystack.top() );
                    ans = ( ans < cnt ? cnt : ans );
                }else dex = i;
            }
        }
        return ans;
    }
};