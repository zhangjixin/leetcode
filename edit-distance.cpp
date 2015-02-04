class Solution {
public:
    int minDistance(string word1, string word2) {
        int dex(1), len1 = word1.size(), len2 = word2.size();
        int ans[2][len2 + 1];
        for (int i = 0; i <= len2; ++i) ans[0][i] = i;
        for (int i = 1; i <= len1; ++i) {
            ans[dex][0] = i;
            for (int j = 1; j <= len2; ++j) {
                if (word1[i-1] == word2[j-1]) {
                    ans[dex][j] = ans[dex^1][j-1];
                } else {
                    ans[dex][j] = 1 + min(ans[dex][j-1], min(ans[dex^1][j-1], ans[dex^1][j]));
                }
            }
            dex ^= 1;
        }
        return ans[dex^1][len2];
    }
};
