class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int ans = num[0] + num[1] + num[2];
        int i = 0, j = 0, k = 0, len = num.size(), tmp;
        
        sort(num.begin(), num.end());
        while (i < len - 2) {
            j = i + 1, k = len - 1;
            while(j < k) {
                tmp = num[i] + num[j] + num[k];
                if(abs(tmp - target) < abs(ans - target)) {
                    ans = tmp;
                }
                if(tmp < target) ++j;
                else if(tmp > target) --k;
                else return target;
            }
            ++i;
        }
        return ans;
    }
};