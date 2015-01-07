class Solution {
public:
    string countAndSay(int n) {
        string ans[2]={"1",""};
        int dex = 0;
        for(int i = 1; i < n; ++i) {
            ans[dex^1] ="";
            for(int j = 0, len = ans[dex].size(), cnt = 1; j < len;) {
                while(j < len -1 && ans[dex][j] == ans[dex][j+1]) ++j, ++cnt;
                ans[dex^1] += char(cnt+'0');
                ans[dex^1] += ans[dex][j++];
                cnt = 1;
            }
            dex ^= 1;
        }
        return ans[dex];
    }
};
