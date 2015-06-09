class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        return doit(nums, 0, len-1, k);
    }
    int doit(vector<int>& nums, int L, int R, int k) {
        int idx = L, val = nums[L], i = L + 1, j = R;
        while (i <= j) {
            if (nums[i] < val) nums[idx++] = nums[i++];
            else swap(nums[i], nums[j--]);
        }
        nums[idx] = val;
        if (k == R - idx + 1) return val;
        else if (k < R - idx + 1) return doit(nums, idx + 1, R, k);
        else return doit(nums, L, idx - 1, k - (R - idx + 1));
    }
};