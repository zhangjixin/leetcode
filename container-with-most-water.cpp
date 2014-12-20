/*
class Solution {
public:

    int maxArea(vector<int> &height) {
        int len = height.size();
        int ans = 0, ldex = len, lval, rdex = 0, rval;
        Myval myval[len];
        for(int i = 0; i < len; ++i){
            myval[i].dex = i+1;
            myval[i].val = height[i];
        }
        sort(myval, myval+len);
        ldex = rdex = myval[0].dex;
        for(int i = 1; i < len; ++i) {
            lval = abs(myval[i].dex - ldex);
            rval = abs(myval[i].dex - rdex);
            ans = max(ans, (lval > rval ? lval : rval) * myval[i].val);
            rdex = max(rdex, myval[i].dex);
            ldex = min(ldex, myval[i].dex);
        }
        return ans;
    }
private:
    struct Myval{
        int val, dex;
        Myval(): val(0), dex(0) {}
        bool operator<(const Myval i) const{
            return val > i.val;
        }
    };
};
*/
class Solution {
public:

    int maxArea(vector<int> &height) {
        int L = 0, R = height.size() - 1;
        int ans = 0, myarea = 0, tmp = 0;
        while(L < R) {
            tmp = min(height[L], height[R]);
            myarea = (R - L) * tmp;
            ans = max(ans, myarea);
            while(tmp >= height[L]) {
                ++L;
            }
            while(tmp >= height[R]) {
                --R;
            }
        }
        return ans;
    }
};