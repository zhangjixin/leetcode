class Solution {
public:
    string addBinary(string a, string b) {
        bool flag = false;
        int lena = a.size() - 1, lenb = b.size() - 1, k = max(lena, lenb);
        string ans;
        lena > lenb ? ans = a : ans = b;
        while (lena >= 0 && lenb >= 0) {
            if (a[lena] == '1' && b[lenb] == '1') {
                ans[k--] = flag ? '1' : '0';
                flag = true;
            } 
            else if (a[lena] == '1' || b[lenb] == '1') {
                ans[k--] = flag ? '0' : '1';
            }
            else {
                ans[k--] = flag ? '1' : '0';
                flag = false;
            }
            --lena, --lenb;
        }
        lena < 0 ? doit(b, flag, ans, k) : doit (a, flag, ans, k);
        if (flag) {
            ans.insert(ans.begin(), '1');
        }
        return ans;
    }
private:
    void doit(string str, bool &flag, string &ans, int k) {
        while (k >= 0) {
            if (flag && str[k] == '1') {
                ans[k--] = '0';
            } else {
                ans[k] = flag ? '1' : ans[k];
                flag = false;
                return;
            }
        }
    }
};
