class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        long long flag = (1LL << n) -1;
        vector<string> perline;
        vector<vector<string> > ans;
        doit(0, 0, 0, perline, ans, flag, n);
        return ans;
    }
private:
    void doit(long long row, long long ld, long long rd, vector<string> &perline, vector<vector<string> > &ans, long long flag, int n) {
        if (row == flag) {
            ans.push_back(perline);
        } else {
            long long pos = flag & ~(row | ld | rd), p;
            string str(n, '.');
            while (pos != 0) {
                p = pos & -pos;
                pos -= p;
                str[int(log2(p))] = 'Q';
                perline.push_back(str);
                doit(row+p, (ld+p) << 1, (rd+p) >> 1, perline, ans, flag, n);
                str[int(log2(p))] = '.';
                perline.pop_back();
            }
        }
    }
};