class Solution {
public:
    string convertToTitle(int n) {
        string ans("");
        int k(n), h(0);
        while (k > 26) {
            h = k % 26;
            ans += ('A' + (h ? h-1 : 25));
            k /= 26;
            if (h == 0) --k;
        }
        ans += ('A' + k - 1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
