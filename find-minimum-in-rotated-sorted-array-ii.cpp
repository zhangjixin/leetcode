class Solution {
public:
    int findMin(vector<int> &num) {
        int len = num.size(), left = 0, right = len - 1, mid = 0;
        while (left < right) {
            mid = left + ((right - left) >> 1);
            if (num[left] < num[right]) return num[left];
            if (num[mid] > num[right]) {
                left = mid + 1;
            }
            else if (num[mid] < num[right]){
                right = mid;
            }
            else {
                if (num[left] == num[right])
                    ++left, --right;
                else
                    right = mid;
            }
        }
        return num[right];
    }
};