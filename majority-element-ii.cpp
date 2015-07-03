class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int len = nums.size(), val[2][2] = {0};
        for (int i = 0; i < len; ++i) {
            if (nums[i] == val[0][0]) ++val[0][1];
            else if (nums[i] == val[1][0]) ++val[1][1];
            else if (val[0][1] == 0) val[0][0] = nums[i], val[0][1] = 1;
            else if (val[1][1] == 0) val[1][0] = nums[i], val[1][1] = 1;
            else --val[0][1], --val[1][1];
        }
        val[0][1] = val[1][1] = 0;
        for (int i = 0; i < len; ++i) {
            if (nums[i] == val[0][0]) ++val[0][1];
            else if (nums[i] == val[1][0]) ++val[1][1];
        }
        len /= 3;
        vector<int> ret;
        if (val[0][1] > len) ret.push_back(val[0][0]);
        if (val[1][1] > len) ret.push_back(val[1][0]);
        return ret;
    }
};