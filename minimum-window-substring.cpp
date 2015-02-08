class Solution {
public:
    string minWindow(string S, string T) {
        int lenT = T.size(), lenS = S.size(), cnt(0);
        int left(-1), right(lenS);
        int mymap[300] = {0}, val[300] = {0};
        for (int i = 0; i < lenT; ++i) {
            ++mymap[T[i]];
        }
        for (int i = 0, j = 0; i < lenS; ++i) {
            ++val[S[i]];
            if (val[S[i]] <= mymap[S[i]]) {
                ++cnt;
            }
            if (cnt == lenT) {
                while (val[S[j]] > mymap[S[j]]) {
                    --val[S[j++]];
                }
                if (i - j < right - left) {
                    left = j, right = i;
                }
                --val[S[j++]];
                --cnt;
            }
        }
        return left == -1 ? "" : S.substr(left, right - left + 1);
    }
};