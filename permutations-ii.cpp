class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > ans;
        doit(0, ans, num, num.size());
        return ans;
    }
private:
    void doit(int dex, vector<vector<int> > &ans, vector<int> &num, int len) {
        if (dex >= len) {
            ans.push_back(num);
            return;
        }
        map<int, bool> used;
        for (int i = dex; i < num.size(); ++i) {
            if (i > dex && (num[i] == num[dex] || used.find(num[i]) != used.end())) {
                continue;
            }
            used[num[i]] = true;
            swap(num[dex], num[i]);
            doit(dex+1, ans, num, len);
            swap(num[dex], num[i]);
        }
    }
};
