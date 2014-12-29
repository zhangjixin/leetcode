class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if(n == 0) return ans;
        doit(n, n, "", ans);
        return ans;
    }
private:
    void doit(int m, int n, string str, vector<string> &ans) {
        if(m == 0 && n == 0) {
            ans.push_back(str);
            return;
        }
        if(m > 0) doit(m-1, n, str+"(", ans);
        if(m < n) doit(m, n-1, str+")", ans);
    }
};