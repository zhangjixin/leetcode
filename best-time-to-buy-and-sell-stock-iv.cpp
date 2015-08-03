class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if (k >= len/2)
            return pruning(prices);
        vector<int> buy(k+1,INT_MIN), sell(k+1, 0);
        for (int i = 0; i < len; ++i) {
            for (int j = 1; j <= k; ++j) {
                buy[j] = max(buy[j], sell[j-1] - prices[i]);
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }
        return sell[k];
    }
    int pruning(vector<int> &prices) {
        int ret = 0;
        for (int i = 1, n = prices.size(); i < n; ++i) {
            if (prices[i] > prices[i-1]) {
                ret += prices[i] - prices[i-1];
            }
        }
        return ret;
    }
};