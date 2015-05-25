class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        int cntS = 1, cntT = 1, val1 = 0, val2 = 0, len = s.size();
        vector<int> Ch2IntS(300, 0);
        vector<int> Ch2IntT(300, 0);
        for (int i = 0; i < len; ++i)
        {
            
            val1 = GetVal(Ch2IntS, cntS, s[i]);
            val2 = GetVal(Ch2IntT, cntT, t[i]);
            if (val1 != val2) 
                return false;
        }
        return true;
    }
    int GetVal(vector<int> &Ch2Int, int &cnt, char ch)
    {
        if (Ch2Int[ch] == 0)
        {
            Ch2Int[ch] = cnt++; 
        }
        return Ch2Int[ch];
    }
};
