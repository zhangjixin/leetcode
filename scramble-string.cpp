class Solution {
public:
    bool isScramble(string s1, string s2) {
        int len = s1.size();
        if (s1 == s2 || len < 1) return true;
        int dp[len][len][len+1];
        for (int k = 1; k <= len; ++k)
        for (int i = 0; i <= len - k; ++i)
        for (int j = 0; j <= len - k; ++j) {
            if (k == 1) {
                dp[i][j][k] = s1[i] == s2[j];
            }
            else {
                dp[i][j][k] = false;
                for (int L = 1; L < k; ++L) {
                    if ((dp[i][j][L] && dp[i+L][j+L][k-L]) || (dp[i][j+k-L][L] && dp[i+L][j][k-L])){
                        dp[i][j][k] = true;
                        break;
                    }
                }
            }
        }
        return dp[0][0][len];
    }
};

#define V3int vector<vector<vector<int>>>
#define cstring const string&
class Solution {
public:
    bool isScramble(string s1, string s2) {
        int len = s1.size();
        if (len < 1 || s1 == s2) return true;
        V3int dp(len, vector<vector<int>>(len, vector<int>(len, -1)));
        return doit(s1, s2, 0, 0, dp, len);
    }
    bool doit(cstring s1, cstring s2, int idx1, int idx2, V3int &dp, int len) {
        
        if (len == 1) return s1[idx1] == s2[idx2];
        if (dp[idx1][idx2][len-1] == 1) return true;
        if (dp[idx1][idx2][len-1] == 0) return false;
        
        for (int i = 1; i < len; ++i) {
            bool ans= (doit(s1,s2,idx1,idx2,dp,i) && doit(s1,s2,idx1+i,idx2+i,dp,len-i));
            if(!ans)
                ans= (doit(s1,s2,idx1,idx2+len-i,dp,i) && doit(s1,s2,idx1+i,idx2,dp,len-i));
            if (ans) {
                dp[idx1][idx2][len-1] = 1;
                return ans;
            }
        }
        dp[idx1][idx2][len-1] = 0;
        return false;
    }
};