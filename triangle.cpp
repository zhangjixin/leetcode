class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int len = triangle.size();
        vector<int> vec(triangle[len-1]);
        for (int i = len - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                vec[j] = triangle[i][j] + min(vec[j], vec[j+1]);
            }
        }
        return vec[0];
    }
};
