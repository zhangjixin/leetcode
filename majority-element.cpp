class Solution {
public:
    int majorityElement(vector<int> &num) {
        int ans(0), len(num.size()), cnt(0);
        for (int i = 0; i < len; ++i) {
            if (cnt == 0) {
                ans = num[i], ++cnt;
            }
            else if(ans != num[i]){
                --cnt;
            }
            else {
                ++cnt;
            }
        }
        return ans;
    }
};