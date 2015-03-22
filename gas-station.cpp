class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int len = gas.size(), sum = 0, ans = 0;
        for (int i = 0; i < len; ++i) {
            gas[i] -= cost[i];
            sum += gas[i];
        }
        if (sum < 0) return -1;
        sum = 0;
        for (int i = 0; i < len; ++i) {
            sum += gas[i];
            if (sum < 0) {
                sum = 0, ans = i + 1;
            }
        }
        return ans;
    }
};
