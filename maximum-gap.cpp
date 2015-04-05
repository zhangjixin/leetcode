class Solution {
public:
    int maximumGap(vector<int> &num) {
        if (num.size() < 2) return 0;
        int len = num.size(), min_num = num[0], max_num = num[0], id = 0;
        for (int i = 1; i < len; ++i) {
            min_num = min(num[i], min_num);
            max_num = max(num[i], max_num);
        }
        int bucket_size = (max_num - min_num) / len + 1, buckets_len = (max_num - min_num) / bucket_size + 1;
        vector<vector<int>> buckets(buckets_len);
        for (int i = 0; i < len; ++i) {
            id = (num[i] - min_num) / bucket_size;
            if (buckets[id].size() == 0) {
                buckets[id].push_back(num[i]), buckets[id].push_back(num[i]);
            }
            else {
                buckets[id][0] = min(buckets[id][0], num[i]);
                buckets[id][1] = max(buckets[id][1], num[i]);
            }
        }
        int ans = 0, pre_id = 0;
        for (int i = 0; i < buckets_len; ++i) {
            if (buckets[i].size() == 0) continue;
            ans = max(ans, buckets[i][0] - buckets[pre_id][1]);
            pre_id = i;
        }
        return ans;
    }
};