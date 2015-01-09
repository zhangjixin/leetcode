class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        //vector<int> myque[target+1];
        vector<vector<int> >ans, vec[target+1];
        int mypack[target+1] = {0}, len = candidates.size(), tlen1;
        sort(candidates.begin(), candidates.end());
        for (int i = 0; i < len; ++i) {
            if (i > 0 && candidates[i] == candidates[i-1]) continue;
            for (int j = candidates[i]; j <= target; ++j) {
                if (j == target) {
                    if (mypack[j - candidates[i]] + candidates[i] == j) {
                        vec[j] = vec[j - candidates[i]];
                        tlen1 = vec[j].size();
                        switch(tlen1) {
                            case 0: ans.push_back({candidates[i]}); break;
                            default: {
                                for(int k = 0; k < tlen1; ++k) {
                                    vec[j][k].push_back(candidates[i]);
                                    ans.push_back(vec[j][k]);
                                }
                            }
                        }
                    }
                }
                else if (mypack[j - candidates[i]] + candidates[i] > mypack[j]) {
                    mypack[j] = mypack[j - candidates[i]] + candidates[i];
                    vec[j] = vec[j - candidates[i]];
                    tlen1 = vec[j].size();
                    switch(tlen1) {
                        case 0: vec[j].push_back({candidates[i]}); break;
                        default: {
                            for(int k = 0; k < tlen1; ++k) vec[j][k].push_back(candidates[i]);
                        }
                    }
                }else if(mypack[j - candidates[i]] + candidates[i] == mypack[j]) {
                    tlen1 = vec[j-candidates[i]].size();
                    switch(tlen1) {
                        case 0: vec[j].push_back({candidates[i]}); break;
                        default:
                            for(int k = 0; k < tlen1; ++k) {
                                vec[j].push_back(vec[j-candidates[i]][k]);
                                vec[j][vec[j].size()-1].push_back(candidates[i]);
                            }
                    }
                }
            }
        }
        return ans;
    }
};
