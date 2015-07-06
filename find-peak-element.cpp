class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        int L = 0, R = len - 1, mid = 0;
        while (L < R) {
            mid = L + ((R - L) >> 1);
            if (mid != 0 && mid != len - 1) {
                if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) {
                    return mid;
                }
                if (nums[mid] < nums[mid-1])
                    R = mid - 1;
                else if (nums[mid] < nums[mid+1])
                    L = mid + 1;
            }
            else {
                if (mid == 0)
                    return nums[0] > nums[1] ? 0 : 1;
                return nums[len-1] > nums[len-2] ? len-1 : len-2;
            }
        }
        return L;
    }
};