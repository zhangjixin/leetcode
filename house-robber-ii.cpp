class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        if (len == 1) return nums[0];
        int inval[3] = {nums[1],nums[0],max(nums[0], nums[1])};
        int nonval[3] = {nums[1],0,nums[1]};
        int ans = inval[2];
        for (int i = 2; i < len; ++i) {
            if (i != len - 1) {
                inval[0] = inval[1] + nums[i]; inval[1] = inval[2]; inval[2] = max(inval[1], inval[0]);
                nonval[0] = nonval[1] + nums[i]; nonval[1] = nonval[2]; nonval[2] = max(nonval[1], nonval[0]);
            }
            else {
                ans = max(ans, inval[2]);
                nonval[2] = max(nonval[2], nonval[1] + nums[i]);
                ans = max(nonval[2], ans);
            }
        }
        return ans;
    }
};