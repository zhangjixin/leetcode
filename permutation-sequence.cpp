class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> num;
        int val(1), grop(0);
        stringstream ans;
        for (int i = 1; i < n; ++i) {
            num.push_back(i);
            val *= i;
        }
        num.push_back(n);
        while (n--) {
            grop = (k-1) / val;
            ans << num[grop];
            k -= grop * val;
            val /= (n == 0 ? 1 : n);
            num.erase(num.begin() + grop);
        }
        return ans.str();
    }
};