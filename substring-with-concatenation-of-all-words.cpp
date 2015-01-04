/**bad solution
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ans;
        if(S.size()==0 || L.size()==0 || L[0].size()==0) return ans;
        int slen = S.size(), llen = L.size(), wlen = L[0].size();
        string str;
        map<string, int> mymap, tmp;
        
        for(int i = 0; i < llen; ++i) ++mymap[L[i]];

        for(int i = 0, j = 0; i <= slen-llen*wlen; ++i) {
            tmp.clear();
            for(j = 0; j < llen; ++j) {
                str = S.substr(i+j*wlen, wlen);
                if( tmp[str] < mymap[str]) {
                    ++tmp[str];
                }else break;
            }
            if(j == llen) ans.push_back(i);
        }

        return ans;
    }
};
*/

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> res;
        if(S.size()==0 || L.size()==0 || L[0].size()==0) return res;
        int slen = S.size(), llen = L.size(), wlen = L[0].size();
        string str;
        map<string, int> mymap, tmp;

        for(int i = 0; i < llen; ++i) ++mymap[L[i]];

        for(int i = 0, cnt = 0, ans = 0; i < wlen; i+=1) {
            tmp.clear();
            cnt = 0, ans = i;
            for(int j = i; j <= slen-wlen; j += wlen) {
                str = S.substr(j, wlen);
                if(!mymap.count(str)) {
                    tmp.clear();
                    cnt = 0, ans = j+wlen;
                    continue;
                }
                ++cnt;
                ++tmp[str];
                if(tmp[str] > mymap[str]) {
                    string sub;
                    do{
                        sub = S.substr(ans, wlen);
                        --tmp[sub];
                        --cnt;
                        ans += wlen;
                    }while(sub != str);
                }
                if(cnt == llen) {
                    res.push_back(ans);
                    str = S.substr(ans, wlen);
                    --tmp[str];
                    --cnt;
                    ans += wlen;
                }
            }
        }

        return res;
    }
};