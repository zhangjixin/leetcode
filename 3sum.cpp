class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > ans;
        map<int, int> mymap;
        int rem = 0;
        sort(num.begin(), num.end());
        for(int i = 0; i < num.size(); ++i) {
            if(mymap.count(num[i]) <= 0){
                mymap[num[i]] = 1;
            }else{
                ++mymap[num[i]];
            }
        }
        for(int i = 0; i < num.size(); ++i) {
            if(i > 0 && num[i] == num[i-1])
            continue;
            --mymap[num[i]];
            for(int j = i+1; j < num.size(); ++j) {
                if(j > i+1 && num[j] == num[j-1])
                continue;
                --mymap[num[j]];
                rem = 0 - num[i] - num[j];
                if(mymap[rem] > 0 && rem >= num[i] && rem >= num[j]) {
                    ans.push_back({num[i], num[j], rem});
                }
                ++mymap[num[j]];
                if(rem < 0)
                    break;
            }
            ++mymap[num[i]];
            if(num[i] > 0)
            return ans;
        }
        return ans;
    }
};

