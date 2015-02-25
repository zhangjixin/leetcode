class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1(s1.size()), len2(s2.size());
        if (len1 + len2 != s3.size()) return false;
        vector<vector<bool> > vec(len1 + 1, vector<bool>(len2 + 1, false));
        vec[0][0] = true;
        for (int i = 1; i <= len1; ++i) {
            if (s1[i-1] == s3[i-1]) vec[i][0] = true;
            else break;
        }
        for (int i = 1; i <= len2; ++i) {
            if (s2[i-1] == s3[i-1]) vec[0][i] = true;
            else break;
        }
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                if (s1[i-1] == s3[i+j-1]) vec[i][j] = vec[i-1][j] || vec[i][j];
                if (s2[j-1] == s3[i+j-1]) vec[i][j] = vec[i][j-1] || vec[i][j];
            }
        }
        return vec[len1][len2];
    }
};