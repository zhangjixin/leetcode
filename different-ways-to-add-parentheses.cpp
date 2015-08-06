class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        unordered_map<string, vector<int>> umap;
        return divideCal(input, umap);
    }
    vector<int> divideCal(string str, unordered_map<string, vector<int>> &umap) {
		if (umap.find(str) != umap.end())
            return umap[str];
        int num = 0, i = 0, n = str.size();
        string s1, s2;
        vector<int> ret;
        while (i < n && str[i] >= '0' && str[i] <= '9')
            num = num * 10 + (str[i++] - '0');
        for (int i = 0; i < n; ++i) {
            if (str[i] == '+' || str[i] == '-' || str[i] == '*') {
                s1 = str.substr(0, i);
                s2 = str.substr(i+1);
                vector<int> vec1 = umap.find(s1) == umap.end() ? divideCal(s1, umap) : umap[s1];
                vector<int> vec2 = umap.find(s2) == umap.end() ? divideCal(s2, umap) : umap[s2];
                for (auto it1 = vec1.begin(); it1 != vec1.end(); ++it1) {
                    for (auto it2 = vec2.begin(); it2 != vec2.end(); ++it2) {
                        if (str[i] == '+') {
                            ret.push_back(*it1 + *it2);
                        }
                        else if (str[i] == '-') {
                            ret.push_back(*it1 - *it2);
                        }
                        else {
                            ret.push_back(*it1 * *it2);
                        }
                    }
                }
            }
        }
        if (ret.size() == 0)
            ret.push_back(num);
        umap[str] = ret;
        return ret;
    }
};