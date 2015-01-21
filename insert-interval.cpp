/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> ans;
        for (int i = 0, len = intervals.size(); i < len; ++i) {
            if (intervals[i].end < newInterval.start) {
                ans.push_back(intervals[i]);
            } else if (newInterval.end < intervals[i].start) {
                ans.push_back(newInterval);
                ans.insert(ans.end(), intervals.begin() + i, intervals.end());
                return ans;
            } else {
                newInterval.start = min(intervals[i].start, newInterval.start);
                newInterval.end = max(intervals[i].end, newInterval.end);
                for (int j = i + 1; j < len; ++j) {
                    if (intervals[j].start > newInterval.end) {
                        ans.push_back(newInterval);
                        ans.insert(ans.end(), intervals.begin()+j, intervals.end());
                        return ans;
                    }
                    newInterval.end = max(intervals[j].end, newInterval.end);
                }
                break;
            }
        }
        ans.push_back(newInterval);
        return ans;
    }
};
