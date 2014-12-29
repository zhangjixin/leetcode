class Solution {
public:
    bool isValid(string s) {
        for(int i = 0; i < s.size(); ++i) {
            if(!isValid(s[i]))
                return false;
        }
        if(!mystack.empty()) return false;
        return true;
    }
private:
    stack<char> mystack;
    
    bool isValid(char ch) {
        switch(ch) {
            case '(' : 
            case '{' : 
            case '[' : 
                mystack.push(ch); return true;
            default: {
                if(mystack.size() <= 0) return false;
                char chr = mystack.top();
                mystack.pop();
                if(getChar(ch) == chr) return true;
                return false;
            }
        }
    }
    
    char getChar(char ch) {
        switch(ch) {
            case ')' : return '(';
            case '}' : return '{';
            case ']' : return '[';
        }
    }
};
