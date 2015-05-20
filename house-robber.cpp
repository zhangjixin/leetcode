class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() <= 0) return 0;
        int ans[3] = {nums[0], 0, nums[0]};
        for (int i = 1, len = nums.size(); i < len; ++i)
        {
            ans[0] = ans[1] + nums[i];
            ans[1] = ans[2];
            ans[2] = max(ans[0], ans[1]);
        }
        return ans[2];
    }
};