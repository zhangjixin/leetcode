class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        int n = S.size(), len = 1 << n;
        vector<vector<int> > ans;
        vector<int> vec;
        sort(S.begin(), S.end());
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) {
                    vec.push_back(S[j]);
                }
            }
            ans.push_back(vec);
            vec.clear();
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > ans;
        vector<int> vec;
        doit(0, S, vec, ans);
        return ans;
    }
private:
    void doit(int i,const vector<int> &S, vector<int> vec, vector<vector<int> > &ans) {
        if (i == S.size()) {
            ans.push_back(vec);
            return;
        }
        doit(i+1, S, vec, ans);
        vec.push_back(S[i]);
        doit(i+1, S, vec, ans);
    }
};