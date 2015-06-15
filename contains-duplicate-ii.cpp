class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> uset;
        for (int i = 0, len = nums.size(); i < len; ++i) {
            if (uset.find(nums[i]) == uset.end())
                uset.insert(nums[i]);
            else
                return true;
            if (i >= k)
                uset.erase(nums[i - k]);
        }
        return false;
    }
};