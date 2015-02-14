class Solution {
public:
    bool search(int A[], int n, int target) {
        int i(0), j(n-1), mid;
        while (i <= j) {
            if (A[i] == A[j] && A[i] != target) {
                ++i, --j;
                continue;
            }
            mid = (i + j) >> 1;
            if (A[mid] == target) return true;
            if (A[mid] > A[j]) {
                if (target > A[mid] || target <= A[j]) {
                    i = mid + 1;
                }
                else {
                    j = mid - 1;
                }
            }
            else {
                if (target < A[mid] || target > A[j]) {
                    j = mid - 1;
                }
                else {
                    i = mid + 1;
                }
            }
        }
        return false;
    }
};