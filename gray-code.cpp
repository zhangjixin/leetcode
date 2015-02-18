class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        for (int i = 0, len = (1 << n) - 1; i <= len; ++i) {
            ans.push_back(i^(i >> 1));
        }
        return ans;
    }
};