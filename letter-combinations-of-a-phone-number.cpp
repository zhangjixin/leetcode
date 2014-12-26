class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        str = digits;
        doit(0, digits, ans);
        return ans;
    }
private:
    string str;
    string num2str(int num) {
        switch(num) {
            case 2 : return "abc";
            case 3 : return "def";
            case 4 : return "ghi";
            case 5 : return "jkl";
            case 6 : return "mno";
            case 7 : return "pqrs";
            case 8 : return "tuv";
            case 9 : return "wxyz";
            default : return " ";
        }
    }
    //const vector<string> num2ch = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void doit(int k, const string digits, vector<string> &ans) {
        if(k == digits.size()) {
            ans.push_back(str);
            return;
        }
        for(int i = 0; i < num2str(digits[k]-'0').size(); ++i) {
            str[k] = num2str(digits[k] - '0')[i];
            doit(k+1, digits, ans);
        }
    }
};