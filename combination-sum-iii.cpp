class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> vec;
        doit(ans, vec, n, k, 0, 0);
        return ans;
    }
    void doit(vector<vector<int>> &ans, vector<int> vec, int n, int k, int val, int sum) {
        if (k == 1) {
            int t = n - sum;
            if (t > val && t <= 9) {
                vec.push_back(t);
                ans.push_back(vec);
            }
            return ;
        }
        for (int i = val + 1; i <= 9; ++i) {
            vec.push_back(i);
            doit(ans, vec, n, k-1, i, sum + i);
            vec.pop_back();
        }
    }
};