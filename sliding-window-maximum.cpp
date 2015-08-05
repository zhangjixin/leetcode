class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        deque<int> deq;
        for (int i = 0, n = nums.size(); i < n; ++i) {
            if (!deq.empty() && deq.front() == i - k) 
                deq.pop_front();
            while (!deq.empty() && nums[deq.back()] <= nums[i]) {
                deq.pop_back();
            }
            deq.push_back(i);
            if (i >= k-1)
                ret.push_back(nums[deq.front()]);
        }
        return ret;
    }
};