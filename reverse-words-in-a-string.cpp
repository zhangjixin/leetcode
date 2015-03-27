class Solution {
public:
    void reverseWords(string &s) {
        int len(s.size()), i(0), j(0), k(0);
        while (j < len) {
            while (i < len && s[i] == ' ') ++i;
            j = i;
            while (j < len && s[j] != ' ') ++j;
            myreverse(s, k, i, j - 1);
            i = j;
        }
        s = s.substr(0, max(0, k - 1));
        reverse(s.begin(), s.end());
    }
private:
    void myreverse(string &s, int &k, int i, int j) {
        if (i <= j) {
            if (k == i) {
                k = j + 2;
                while (i < j) swap(s[i++], s[j--]);
            } else {
                int ii = i, jj = j;
                while (ii < jj) swap(s[ii++], s[jj--]);
                while (i <= j) s[k++] = s[i++];
                s[k++] = ' ';
            }
        }
    }
};