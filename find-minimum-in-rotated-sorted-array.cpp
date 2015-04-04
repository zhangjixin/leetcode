class Solution {
public:
    int findMin(vector<int> &num) {
        int len = num.size(), left = 0, right = len - 1, mid = 0;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (mid == right) return num[mid];
            if (num[mid] > num[right]) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return num[right];
    }
};