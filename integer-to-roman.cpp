/*
* I 1
* V 5
* X 10
* L 50
* C 100
* D 500
* M 1000
*/
class Solution {
public:
    string intToRoman(int num) {
        int len = 13;
        int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string sym[] = {"M", "CM", "D","CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string ans = "";
        for(int i = 0 ;i < len; ++i) {
            while(num >= val[i]) {
                ans += sym[i];
                num -= val[i];
            }
        }
        return ans;
    }
};