class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        const char *pp(NULL), *ss(NULL);
        while (*s) {
            if (*p == *s || *p == '?') {
                ++p, ++s;
            } else if (*p == '*') {
                ++p;
                if (*p == '\0') return true; 
                pp = p, ss = s;
            } else {
                if(pp) {
                    p = pp;
                    s = ++ss;
                } else {
                    return false;
                }
            }
        }
        while (*p == '*') ++p;
        return (*p == '\0');
    }
};
