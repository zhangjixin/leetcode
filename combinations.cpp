class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > ans;
        vector<int> vec(k, 0);
        doit(n, k, vec, ans);
        return ans;
    }
private:
    void doit(int i, int k, vector<int> &vec, vector<vector<int> > &ans) {
        if (k == 0) {
            ans.push_back(vec);
            return;
        }
        for (int j = i; j >= 1; --j) {
            vec[k-1] = j;
            doit(j-1, k-1, vec, ans);
        }
    }
};