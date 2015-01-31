class Solution {
public:
    int sqrt(int x) {
        if (x <= 0) return 0;
        double flag = 0, cur = max (x/2, 1);
        while (flag != cur) {
            flag = cur;
            cur = (cur + x / cur) / 2;
        }
        return (int)cur;
    }
};
/*
http://www.matrix67.com/blog/archives/361
http://zh.wikipedia.org/zh/%E7%89%9B%E9%A1%BF%E6%B3%95
http://en.wikipedia.org/wiki/Newton's_method
*/