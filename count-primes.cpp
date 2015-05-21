class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<int> vec(n+1, 0);
        vec[0] = 2;
        int ans = 1;
        for (int i = 3; i < n; i += 2) {
            if (vec[i] == 0) 
                vec[ans++] = i;
            for (int j = 0; j < ans && i*vec[j] < n; ++j) {
                vec[i * vec[j]] = 1;
                if ((i % vec[j]) == 0) break;
            }
        }
        return ans;
    }
};