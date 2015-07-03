class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        int i = 0, len = nums.size();
        while(i < len) {
            stringstream ss;
            bool flag = false;
            ss << nums[i];
            while (i + 1 < len && nums[i+1] - nums[i] == 1) flag = true, ++i;
            if (flag) ss << "->" << nums[i];
            ret.push_back(ss.str());
            ++i;
        }
        return ret;
    }
};