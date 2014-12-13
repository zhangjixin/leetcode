class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int pa = 0, flag[130] = {0} , len = s.size();
        if(len == 0)
            return 0;
        int val = (int)s[pa], ans = 1, cnt = 1, valtmp;
        flag[val] = 1;
        for(int i = 1; i < len; ++i) {
            val = (int)s[i];
            if(flag[val]) {
                while(flag[val]) {
                    valtmp = (int)s[pa];
                    flag[valtmp] = 0;
                    ++pa;
                    --cnt;
                }
                flag[val] = 1;
                ++cnt;
            }else{
                flag[val] = 1;
                ++cnt;
                if(cnt > ans)
                    ans = cnt;
            }
        }
        return ans;
    }
};
