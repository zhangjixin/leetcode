/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        unordered_map<double, int> umap;
        int len = points.size(), ans = 0, cnt = 0, cnt2 = 0;
        for (int i = 0; i < len; ++i) {
            umap.clear(), cnt = 0, cnt2 = 0;
            int tmp = 0;
            for (int j = 0; j < len; ++j) {
                if (points[i].x == points[j].x) {
                    if (points[i].y == points[j].y)
                        ++cnt;
                    else 
                        ++cnt2;
                } else {
                    double delta = double(points[i].y - points[j].y) / (points[i].x - points[j].x);
                    tmp = max(++umap[delta], tmp);
                }
            }
            tmp = max(tmp, cnt2) + cnt;
            ans = max(tmp, ans);
        }
        return ans;
    }
};
