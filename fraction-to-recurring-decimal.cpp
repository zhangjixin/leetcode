class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans = "";
        if (denominator == 0) return ans;
        if (numerator == 0) return "0";
        long long n = numerator, d = denominator;
        bool flag = true;
        if (n < 0) n = -n, flag = !flag;
        if (d < 0) d = -d, flag = !flag;
        long long divis = n / d, rem = n % d;
        if (!flag) ans.push_back('-');
        ans += to_string(divis);
        if (rem == 0) return ans;
        ans.push_back('.');
        unordered_map<long long, int> uset;
        for (int pos = ans.size(); rem != 0; ++pos, rem = (rem * 10) % d) {
            if (uset.find(rem) != uset.end()) {
                ans.insert(ans.begin() + uset[rem], '(');
                ans.push_back(')');
                return ans;
            }
            uset[rem] = pos;
            ans.push_back(rem * 10 / d + '0');
        }
        return ans;
    }
};
