class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<int> mypath;
        vector<vector<int> > ans;
        sort(num.begin(), num.end());
        doit(num, 0, target, mypath, ans);
        return ans;
    }
private:
    void doit(vector<int> &num, int k, int rem, vector<int> &path, vector<vector<int> > &ans) {
        if(rem == 0) {
            ans.push_back(path);
            return;
        }
        for (int i = k; i < num.size(); ++i) {
            if(i > k && num[i] == num[i-1]) continue;
            if (num[i] - rem > 0) return;
            path.push_back(num[i]);
            doit(num, i+1, rem-num[i], path, ans);
            path.pop_back();
        }
    }
};
