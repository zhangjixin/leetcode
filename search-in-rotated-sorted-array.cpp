/*
class Solution {
public:
    int search(int A[], int n, int target) {
        if(A[0] == target) return 0;
        if(A[n-1] == target) return n-1;
        return doit(A, 0, n-1, target);
    }
private:
    int doit(int a[], int left, int right, int target) {
        if(left > right) return -1;
        if(left == right) return a[left] == target ? left : -1;
        if(a[left] == target) return left;
        if(a[right] == target) return right;
        int mid = (left+right) >> 1;
        if(a[mid] == target) return mid;
        if(a[left] < a[right]) {
            if(a[mid] < target) return doit(a, mid+1, right, target);
            else return doit(a, left, mid-1, target);
        }else {
            if(a[left] < a[mid]) {
                if(a[mid] > target && a[left] < target) return doit(a, left, mid-1,target);
                else return doit(a, mid +1, right, target);
            }
            else if(a[left] > a[mid]) {
                if(a[mid] < target && a[right] > target) return doit(a, mid+1, right, target);
                else return doit(a, left, mid-1, target);
            }
            else return a[right] == target ? right : -1;
        }
    }
};
*/
class Solution {
public:
    int search(int A[], int n, int target) {
        int left = 0, right = n-1, mid;
        while(left <= right) {
            mid = (left+right) >> 1;
            if(A[mid] == target) return mid;
            if(A[mid] >= A[left]) {
                if(A[mid] < target || target < A[left]) {
                    left = mid + 1;
                }else right = mid;
            }else {
                if(A[mid] > target || target > A[right]) {
                    right = mid;
                }else left = mid + 1;
            }
        }
        return -1;
    }
};
