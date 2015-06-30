#define LL long long
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int len = nums.size();
        if (k < 1 || t < 0 ||  len < 2) return false;
        unordered_map<LL, LL> umap;
        LL MinVal = (LL)nums[0], bucket = 0;
        for (int i = 1; i < len; ++i)
            MinVal = min(MinVal, (LL)nums[i]);
        for (int i = 0; i < len; ++i) {
            if (i > k) {
                bucket = ((LL)nums[i - k - 1] - MinVal) / ((LL)t + 1);
                umap.erase(bucket);
            }
            bucket = ((LL)nums[i] - MinVal) / ((LL)t + 1);
            if (umap.find(bucket) != umap.end()) return true;
            if (umap.find(bucket + 1) != umap.end() && umap[bucket+1] - nums[i] <= t) return true;
            if (umap.find(bucket - 1) != umap.end() && nums[i] - umap[bucket-1] <= t) return true;
            umap[bucket] = nums[i];
        }
        return false;
    }
};