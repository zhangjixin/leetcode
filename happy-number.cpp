class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> uset;
        int m = 0;
        while (true) {
            m = 0;
            while (n) {
                m += pow((n % 10), 2);
                n /= 10;
            }
            n = m;
            if (n == 1) return true;
            if (uset.find(n) != uset.end()) return false;
            uset.insert(n);
        }
        return true;
    }
};