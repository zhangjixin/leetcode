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
    int romanToInt(string s) {
        int ans = 0, i = 0;
        int len = s.size();
        while(i < len ){
            if( i < len - 1 && C2Int(s[i]) < C2Int(s[i+1])){
                ans += C2Int(s[i+1]) - C2Int(s[i]);
                i += 2;
            }else {
                ans += C2Int(s[i]);
                ++i;
            }
        }
        return ans;
    }
private:
    int C2Int(char c) {
        switch (c) {
            case 'I' : return 1;
            case 'V' : return 5;
            case 'X' : return 10;
            case 'L' : return 50;
            case 'C' : return 100;
            case 'D' : return 500;
            case 'M' : return 1000;
            default : return 0;
        }
    }
};