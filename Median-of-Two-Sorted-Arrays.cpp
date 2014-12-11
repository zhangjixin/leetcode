#define MIN(a, b) a<b?a:b

class Solution {
public:
    double findmid(int a[], int m, int b[], int n, int k) {
        if(m > n)
            return findmid(b, n, a, m, k);
        if(m == 0)
            return b[k-1];
        if(k == 1)
            return MIN(a[0], b[0]);
        int pa = MIN(k>>1, m), pb = k - pa;
        if(a[pa-1] < b[pb-1]){
            return findmid(a+pa, m-pa, b, n, k-pa);
        }else if(a[pa-1] > b[pb-1]){
            return findmid(a, m, b+pb, n-pb, k-pb);
        }else{
            return a[pa-1];
        }
    }
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if((m+n) & 1)
            return findmid(A, m, B, n, ((m+n)>>1) + 1);
        else
            return ( findmid(A, m, B, n, (m+n)>>1) + findmid(A, m, B, n, ((m+n)>>1) + 1) )/2;
    }
};
