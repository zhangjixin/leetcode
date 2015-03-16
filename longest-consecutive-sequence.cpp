class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, int> umap;
        int ans(1), lenL, lenR, sum;
        for (auto it = num.begin(); it != num.end(); ++it) {
            if (umap.find(*it) == umap.end()) {
                lenL = umap.find(*it - 1) == umap.end() ? 0 : umap[*it - 1];
                lenR = umap.find(*it + 1) == umap.end() ? 0 : umap[*it + 1];
                sum = lenL + lenR + 1;
                ans = max(ans, sum);
                umap[*it] = sum;
                umap[*it - lenL] = sum;
                umap[*it + lenR] = sum;
            }
        }
        return ans;
    }
};