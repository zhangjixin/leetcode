/*solution 1
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int left = 0, right = n-1, mid;
        while(left <= right) {
            mid = (left + right) >> 1;
            if(A[mid] == target) return mid;
            if(A[mid] < target) {
                left = mid + 1; continue;
            }else {
                right = mid -1; continue;
            }
        }
        return left;
    }
 }; 
 */

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        return lower_bound(A, A + n, target) - A;
    }
};
