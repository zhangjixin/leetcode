/* solution 1
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int *p = lower_bound(A, A+n, target), i,j;
        if(p == (A+n) || *p != target) return {-1, -1};
        i = p - A, j = i + 1;
        while(A[j] == A[i] && j < n) ++j;
        return {i, j - 1};
    }
};
*/

/*soluton 2
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int *p = lower_bound(A, A+n, target), *q = p+1;
        if(p == (A+n) || *p != target) return {-1, -1};
        while(*q == *p && q != A+n) ++q; 
        return {p-A, (q-A)-1};
    }
};
*/
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        
        int left = 0, right = n-1, mid, flag = 0;
        while(left <= right) {
            mid = (left + right) >> 1;
            if(A[mid] == target) {
                flag = 1; break;  
            } 
            if(A[mid] < target) {
                left = mid + 1; continue;
            }else {
                right = mid - 1; continue;
            }
        }
        if(flag) {
            left = mid -1, right = mid + 1;
            while(A[left] == A[mid] && left >= 0) --left;
            while(A[right] == A[mid] && right < n) ++right;
            return {left + 1, right - 1};
        }
        return {-1, -1};
    }
};
