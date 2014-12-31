class Solution {
public:
    int strStr(char *haystack, char *needle) {
        int nlen = strlen(needle), hlen = strlen(haystack);
        if(nlen == 0) return 0;
        
        int p[nlen], ans = 0, j = 0, k = -1;
        getNext(p, needle, nlen);
        
        for(int i = 0; i < hlen; ++i) {
            while(k > -1 && haystack[i] != needle[k+1]) k = p[k];
            if(needle[k+1] == haystack[i]) ++k;
            if(k == nlen -1) return i-nlen+1;
        }
        return -1;
    }
    
private:
    void getNext(int p[], char *pstr, int len) {
        p[0] = -1;
        int k = -1;
        for(int i = 1; i < len; ++i) {
            while(k > -1 && pstr[k+1] != pstr[i]) k = p[k];
            if(pstr[k+1] == pstr[i]) ++k;
            p[i] = k;
        }
    }
};
