class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        int n = words.size(), len = L, i = 0, k = 0;
        vector<string> ans, vec;
        string s("");
        while (i < n) {
            if ((int)words[i].size() <= len) {
                vec.push_back(words[i]);
                k += words[i].size();
                len -= words[i].size() + 1;
                ++i;
            } else {
                s = doit(vec, L - k);
                ans.push_back(s);
                len = L, k = 0;
                vec.clear();
            }
        }
        if (vec.size() > 0) {
            s = vec[0];
            for (i = 1, k = vec[0].size(); i < vec.size(); ++i) {
                s += " " + vec[i];
                k += vec[i].size() + 1;
            }
            s.append(L - k, ' ');
            ans.push_back(s);
        }
        return ans;
    }
private:
    string doit(const vector<string> &vec, int len) {
        string s = vec[0];
        if (vec.size() == 1) {
            if (len)
                s.append(len, ' ');
        } else {
            int m = vec.size() - 1, k = len / m, rem = len % m;
            for (int j = 1; j <= m; ++j) {
                s.append(k + ((rem--) > 0 ? 1 : 0), ' ');
                s.append(vec[j]);
            }
        }
        return s;
    }
};