class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        if (height.size() < 1) return 0;
        int len = height.size(), right[len], left[len], ans = height[0];
        for (int i = len - 1,j; i >= 0; --i) {
            j = i + 1;
            while (j != len && height[j] >= height[i]) {
                j = right[j];
            }
            right[i] = j;
        }
        for (int i = 0, j; i < len; ++i) {
            j = i - 1;
            while (j != -1 && height[j] >= height[i]) {
                j = left[j];
            }
            left[i] = j;
            ans = max(height[i] * (right[i] - left[i] - 1), ans);
        }
        return ans;
    }
};
