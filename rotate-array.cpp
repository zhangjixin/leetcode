class Solution {
public:
    void rotate(int nums[], int n, int k) {
        k %= n;
        myreverse(nums, 0, n - k - 1);
        myreverse(nums, n - k, n - 1);
        myreverse(nums, 0, n - 1);
    }
private:
    void myreverse(int num[], int i, int j) {
        while (i < j) {
            swap(num[i++], num[j--]);
        }
    }
};