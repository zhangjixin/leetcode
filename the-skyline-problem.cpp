class Solution
{
public:
    class Point
    {
    public:
        int x, y, flag;
        bool operator< (Point re) const
        {
            if (x == re.x) {
                if(flag == re.flag) {
                    return flag == 0 ? y > re.y : y < re.y;
                }
                return flag < re.flag;
            }
            return x < re.x;
        }
    };
    vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings)
    {
        vector<pair<int, int> > ans;
        int len = buildings.size(), cnt = 0;
        Point pt[2*len + 1];
        map<int, int, greater<int> > iMap;
        iMap[0] = 1;
        for (int i = 0, pre = 0; i < len; ++i) {
            if(i > 0) {
                if (buildings[i][0] == buildings[pre][0] && buildings[i][1] == buildings[pre][1]) {
                    if (buildings[i][2] > buildings[pre][2])
                        cnt -= 2, pre = i;
                    else
                        continue;
                }
                else
                    pre = i;
            }
            pt[cnt].x = buildings[i][0], pt[cnt].y = buildings[i][2], pt[cnt].flag = 0;
            ++cnt;
            pt[cnt].x = buildings[i][1], pt[cnt].y = buildings[i][2], pt[cnt].flag = 1;
            ++cnt;
        }
        sort(pt, pt + cnt);

        for (int i = 0; i < cnt; ++i) {
            if (pt[i].flag) {
                iMap[pt[i].y]--;
                if(iMap[pt[i].y] <= 0) {
                    iMap.erase(pt[i].y);
                    if (pt[i].y > iMap.begin()->first)
                        ans.push_back(make_pair(pt[i].x, iMap.begin()->first));
                }
            }
            else {
                if (pt[i].y > iMap.begin()->first )
                    ans.push_back(make_pair(pt[i].x, pt[i].y));
                if (iMap.find(pt[i].y) == iMap.end())
                    iMap[pt[i].y] = 1;
                else
                    iMap[pt[i].y] += 1;
            }
        }
        return ans;
    }

};