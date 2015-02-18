class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > ans;
        vector<int> sset;
        sort(S.begin(), S.end());
        doit(0, S, sset, ans);
        return ans;
    }
private:
    void doit(int k, const vector<int> &s, vector<int> &sset, vector<vector<int> > &ans) {
        if (k >= s.size()) {
            ans.push_back(sset);
            return;
        }
        int i = k, j = k, len = s.size();
        while (j < len && s[j] == s[i]) ++j;
        doit(j, s, sset, ans);
        for (int n = 1; n <= j - i; ++n) {
            sset.push_back(s[i]);
            doit(j, s, sset, ans);
        }
        for (int n = 1; n <= j - i; ++n) {
            sset.pop_back();
        }
    }
};