class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > ans;
        int b, c, tmp, len = num.size();
        sort(num.begin(), num.end());

        for(int i = 0; i < len - 3; ++i ){
            if(i > 0 && (num[i] == num[i-1])) continue;
            for(int j = i + 1; j < len - 2; ++j) {
                if((j > i+1) && (num[j] == num[j-1])) continue;
                b = j + 1, c = len - 1;
                while(b < c){
                    if( (tmp = num[i] + num[j] + num[b] + num[c]) == target) {

                        ans.push_back( GetVec(num[i], num[j], num[b], num[c]));
                        ++b;
                        --c;
                        while(b < c && num[b] == num[b-1]) ++b;
                        while(b < c && num[c] == num[c+1]) --c;
                    }else if(tmp < target) {
                        ++b;
                        while(b < c && num[b] == num[b-1]) ++b;
                    }else {
                        --c;
                        while(b < c && num[c] == num[c+1]) --c;
                    }
                }
            }
        }

        return ans;
    }
private:
    vector<int> GetVec(int a, int b, int c, int d) {
        vector<int> res;
        res.push_back(a), res.push_back(b), res.push_back(c), res.push_back(d);
        return res;
    }
};