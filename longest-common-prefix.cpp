class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.size() <= 0)
            return "";
        string ans = "";
        char ch;
        for(int i = 0; i < strs[0].size(); ++i) {
            ch = strs[0][i];
            for(int j = 1; j < strs.size(); ++j) {
                if( i < strs[j].size()) {
                    if(strs[j][i] != ch) {
                        return ans;
                    }
                }else{
                    return ans;
                }
            }
            ans += ch;
        }
        return ans;
    }
};

