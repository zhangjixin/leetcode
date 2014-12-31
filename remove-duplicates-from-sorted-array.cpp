class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if( n <= 1) return n;
        int i = 0, k = 1;
        for(i = 1; i < n; ++i) {
            if(A[i] != A[i-1]){
                A[k++] = A[i];
            }
        }
        return k;
    }
};