class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() < 1) return 0;
        int len = prices.size(), ans(0), num = prices[len-1];
        vector<int> arry(len, 0);
        for (int i = len - 2; i >= 0; --i) {
            num = max(prices[i], num);
            arry[i] = max(arry[i+1], num - prices[i]);
        }
        num = prices[0];
        for (int i = 0; i < len; ++i) {
            num = min(prices[i], num);
            ans = max(prices[i] - num + arry[i], ans);
        }
        return ans;
    }
};
/*
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int len = prices.size(), val(0), flag = 0, dex(0), ans(0);
        bool key = false;
        node mynode[2];
        for (int i = 1; i < len; ++i) {
            val += prices[i] - prices[i-1];
            if (val < 0) {
                val = 0;
                if (key) {
                    key = false;
                    flag ^= 1;
                }
                dex = i;
            } else if (val > mynode[flag].val) {
                mynode[flag].val = val;
                mynode[flag].i = dex;
                mynode[flag].j = i;
                key = true;
            }
        }
        if (mynode[0].val == 0) {
            ans = mynode[1].val;
            ans = max(ans, mynode[1].val - doit(prices, mynode[1].i, mynode[1].j));
            ans = max(ans, mynode[1].val + doit_back(prices, mynode[1].j, len));
        } else if (mynode[1].val == 0) {
            ans = mynode[0].val;
            ans = max(ans, mynode[0].val - doit(prices, mynode[0].i, mynode[0].j));
            ans = max(ans, mynode[0].val + doit_back(prices, mynode[0].j, len));
        } else {
            ans = mynode[0].val + mynode[1].val;
            ans = max(ans, mynode[0].val - doit(prices, mynode[0].i, mynode[0].j));
            ans = max(ans, mynode[1].val - doit(prices, mynode[1].i, mynode[1].j));
            if (mynode[0].j < mynode[1].j) {
                ans = max(ans, mynode[1].val + doit_back(prices, mynode[1].j, len));
            } else {
                ans = max(ans, mynode[0].val + doit_back(prices, mynode[0].j, len));
            }
        }
        return ans;
    }
private:
    struct node{
        int val, i, j;
        node() : val(0), i(0), j(0) {}
    };
    
    int doit_back(vector<int> &pri, int i, int len) {
        int ret(0), val(0);
        for (int k = i + 1; k < len; ++k) {
            val += pri[k] - pri[k-1];
            if (val < 0) {
                val = 0;
            } else if (val > ret) {
                ret = val;
            }
        }
        return ret;
    }
    int doit(vector<int> &pri, int i, int j) {
        int ret(0), val(0);
        for(int k = i + 1; k <= j; ++k) {
            val += pri[k] - pri[k-1];
            if (val > 0) {
                val = 0;
            } else if (val < ret) {
                ret = val;
            }
        }
        return ret;
    }
};
*/
