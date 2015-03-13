class Solution {
public:
    int compareVersion(string version1, string version2) {
        int v1(0), i(0), v2(0), j(0), len1(version1.size()), len2(version2.size());
        while(i < len1 && j < len2) {
            doit(v1, version1, i, len1);
            doit(v2, version2, j, len2);
            if (v1 != v2) {
                return v1 > v2 ? 1 : -1;
            }
        }
        if (i >= len1 && j >= len2) return 0;
        return i >= len1 ? -1 * GetRet(version2, j, len2) : GetRet(version1, i, len1);
    }
private:
    void doit(int &v,const string &str, int &i,const int &len) {
        v = 0;
        while(i < len && str[i] != '.') {
            v = v*10 + (str[i] - '0');
            ++i;
        }
        ++i;
    }
    int GetRet(const string &str, int i,const int &len) {
        while (i < len && (str[i] == '.' || str[i] == '0')) ++i;
        return i == len ? 0 : 1;
    }
};
