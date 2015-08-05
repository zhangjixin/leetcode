class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1, n = nums.size(), cnt = 0;
        vector<int> ret(n, 0);
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                cnt += 1;
                continue;
            }
            prod *= nums[i];
        }
        if (cnt > 1)
            return ret;
        if (cnt == 1) {
            for (int i = 0; i < n; ++i) {
                if (nums[i] == 0) {
                    ret[i] = prod;
                    break;
                }
            }
        }
        else {
            for (int i = 0; i < n; ++i) {
                ret[i] = prod / nums[i];
            }
        }
        return ret;
    }
};


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n, 1);
        for(int i = 1; i < n; ++i) {
            ret[i] = ret[i-1] * nums[i-1];
        }
        for (int i = n-1, val = 1; i >= 0; val *= nums[i--]) {
            ret[i] *= val;
        }
        return ret;
    }
};