class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> cnt(n+2, 0);
        for (int i = 0; i < n; ++i) {
            if (citations[i] >= n)
                ++cnt[n];
            else
                ++cnt[citations[i]];
        }
        for (int i = n; i >= 0; --i) {
            cnt[i] += cnt[i+1];
            if (cnt[i] >= i)
                return i;
        }
        return 0;
    }
};