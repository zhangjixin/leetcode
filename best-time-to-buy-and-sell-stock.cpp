class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int len = prices.size(), ans(0), val(0);
        for (int i = 1; i < len; ++i) {
            val += prices[i] - prices[i - 1];
            if (val < 0) {
                val = 0;
            } else if (val > ans) {
                ans = val;
            }
        }
        return ans;
    }
};
