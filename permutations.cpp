class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > ans;
        doit(0, ans, num, num.size());
        return ans;
    }
private:
    void doit(int dex, vector<vector<int> > &ans, vector<int> &num, int len) {
        if(dex == len) {
            ans.push_back(num);
            return;
        }
        for (int i = dex; i < len; ++i) {
            swap(num[i], num[dex]);
            doit(dex+1, ans, num, len);
            swap(num[i], num[dex]);
        }
    }
};
