class Solution {
public:
    void sortColors(int A[], int n) {
        int i(0), j(n-1), k(0);
        while (k <= j) {
            switch (A[k]) {
                case 0 : {
                    swap(A[i++], A[k++]);
                    break;
                }
                case 1 : {
                    ++k;
                    break;
                }
                default : {
                    swap(A[k], A[j--]);
                    break;
                }
            }
        }
    }
};