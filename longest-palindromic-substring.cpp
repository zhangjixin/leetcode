class Solution {
public:
    string longestPalindrome(string s) {
        string str = newstring(s);
        string ans = "";
        int len = str.size();
        int flagid = 1, maxlen = 1, maxid = 1;
        memset(flag, 0, sizeof(flag));
        flag[1] = 1;
        for(int i = 2; i < len; ++i) {
            if(i < maxid + maxlen) {
                flag[i] = min(flag[2*maxid - i], maxid+maxlen-i);
            }else{
                flag[i] = 1;
            }
            while(str[i+flag[i]] == str[i-flag[i]]){
                ++flag[i];
            }
            if(flag[i] >= maxlen) {
                maxid = i;
            }
            if(flag[i] > maxlen) {
                maxlen = flag[i];
                flagid = i;
            }
        }
       // cout <<flagid <<" "<<maxlen <<" "<< flagid - maxlen +1 <<" "<< flagid +maxlen -1 <<endl;
        for(int i = flagid - maxlen + 1; i <= flagid + maxlen -1; ++i) {
                if(str[i] != '#')
                    ans += str[i];
        }
        return ans;
    }
private:
    int flag[10100];
    string newstring(string s) {
        string str = "%";
        for(string::iterator it = s.begin(); it != s.end(); ++it){
            str += "#";
            str += (*it);
        }
        str += "#$";
        return str;
    }
};