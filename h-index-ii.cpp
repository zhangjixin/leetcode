class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0, right = n - 1, mid = 0;
        if (n < 1 || citations[right] == 0) return 0;
        while (left <= right) {
            mid = (left + right) >> 1;
            if (citations[n - mid - 1] > mid) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right + 1;
    }
};