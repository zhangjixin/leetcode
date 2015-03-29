class Solution {
public:
    int candy(vector<int> &ratings) {
        int i(0), j(1), ans(1), cnt(1), len(ratings.size()), flag(1);
        while (j < len) {
            if (ratings[j] == ratings[j-1]) {
                ++ans, i = j, cnt = 1, flag = 1;
            }
            if (ratings[j] > ratings[j-1]) {
                ++cnt, i = j;
                ans += cnt, flag = cnt;
            }
            if (ratings[j] < ratings[j-1]) {
                cnt = 1, ans += j - i;
                if (j - i >= flag) ++ans;
            }
            ++j;
        }
        return ans;
    }
};