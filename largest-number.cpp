class Solution {
public:
    class Cmp{
        public:
            bool operator() (const int &a, const int &b) {
                stringstream s1, s2;
                s1 << a << b;
                s2 << b << a;
                return s1.str() > s2.str();
            }
    };
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), Cmp());
        stringstream ss;
        for (int i = 0, n = nums.size(); i < n; ++i) {
            ss << nums[i];
        }
        string ret = ss.str();
        if (ret[0] == '0')
            return "0";
        return ret;
    }
};