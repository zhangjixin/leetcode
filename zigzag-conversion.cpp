class Solution {
public:
    string convert(string s, int nRows) {
        int len = s.size();
        if( (nRows == len) || (nRows == 1))
            return s;
        string istr[nRows + 5];
        int dex = 1, op = -1;
        for(int i = 0; i <= nRows; ++i)
            istr[i] = "";
        istr[1] += s[0];
        for(int i = 1; i < len; ++i) {
            if((dex == 1) || (dex == nRows)){
                op = -op;
            }
            dex += op;
            istr[dex] += s[i];
        }
        for(int i = 1; i <= nRows; ++i){
            istr[0] += istr[i];
        }
        return istr[0];
    }
};