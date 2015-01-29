class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        bool flag = true;
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] == 9) {
                digits[i] = 0;
            } else {
                ++digits[i];
                flag = false;
                break;
            }
        }
        if (flag) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
