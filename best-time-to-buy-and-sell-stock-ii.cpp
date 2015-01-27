class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int len = prices.size(), val(0), ans(0);
        for (int i = 1; i < len; ++i) {
            if ((val = prices[i] - prices[i-1]) <= 0) {
                val = 0;
            } else {
                ans += val;
            }
        }
        return ans;
    }
};
