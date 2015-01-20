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
    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.size() <= 1) return intervals;
        sort(intervals.begin(), intervals.end(), mycmp);
        vector<Interval> ans;
        Interval val(intervals[0].start, intervals[0].end);
        for (int i = 1, len = intervals.size() - 1; i <= len; ++i) {
            if (intervals[i].start <= val.end) {
                val.end = max(intervals[i].end, val.end);
            } else {
                ans.push_back(val);
                val.start = intervals[i].start;
                val.end = intervals[i].end;
            }
        }
        ans.push_back(val);
        return ans;
    }
private:
/*
static bool mycmp(struct Interval &a, struct Interval &b) {
        return a.start < b.start;
    }
*/
    struct myclass{
        bool operator() (Interval a, Interval b) {
            return a.start < b.start;
        }
    }mycmp;
};
