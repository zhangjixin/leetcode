class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size(), cur_idx = -1, pre_idx = 0, ans = len;
        if (len == 0) return 0;
        if (nums[0] >= s) return 1;
        for (int i = 1; i < len; ++i) {
            nums[i] += nums[i - 1];
            if (cur_idx == -1 && nums[i] >= s) {
                cur_idx = i;
            }
        }
        if (nums[len - 1] < len) return 0;
        while (cur_idx < len) {
            while (nums[cur_idx] - nums[pre_idx] >= s) ++pre_idx;
            ans = min(ans, cur_idx - pre_idx + 1);
            ++cur_idx;
        }
        return ans;
    }
};