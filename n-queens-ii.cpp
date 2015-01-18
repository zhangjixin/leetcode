#define lint long long
class Solution {
public:
    int totalNQueens(int n) {
        lint flag = (1LL << n) -1;
        int ans = 0;
        doit(0, 0, 0, ans, flag);
        return ans;
    }
private:
    void doit(lint row, lint ld, lint rd, int &ans, lint flag) {
        if (row == flag) ++ans;
        else {
            lint pos = flag & ~(row | ld | rd), p;
            while (pos != 0) {
                p = pos & -pos;
                pos -= p;
                doit(row+p, (ld+p) << 1, (rd+p) >> 1, ans, flag);
            }
        }
    }
};