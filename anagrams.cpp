class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        map<string, int> strmap;
        vector<string> ans;
        string mystr;
        for (int i = 0, len = strs.size(); i < len; ++i) {
            mystr = strs[i];
            sort(mystr.begin(), mystr.end());
            if (strmap.find(mystr) != strmap.end()) {
                if(strmap[mystr] != -1) {
                    ans.push_back(strs[strmap[mystr]]);
                    strmap[mystr] = -1;
                }
                ans.push_back(strs[i]);
            } else {
                strmap[mystr] = i;
            }
        }
        return ans;
    }
};
