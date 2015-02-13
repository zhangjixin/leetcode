class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() <= 1) return true;
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (!is_valid(s[i])) {
                ++i;
                continue;
            }
            if (!is_valid(s[j])) {
                --j;
                continue;
            }
            if (toupper(s[i++]) != toupper(s[j--])) 
                return false;
        }
        return true;
    }
private:
    bool is_valid(char ch) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
            return true;
        return false;
    }
};