class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n-1;
        while (i < m && j >= 0) {
            if (matrix[i][j] > target) {
                --j;
            }
            else if (matrix[i][j] < target) {
                ++i;
            }
            else {
                return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        return dfs(matrix, 0, m-1, 0, n-1, target);
    }
    bool dfs(vector<vector<int>>& matrix, int hl, int hr, int vl, int vr, int target) {
        if (hl > hr || vl > vr)
            return false;
        int hm = hl + (hr - hl) / 2;
        int vm = vl + (vr - vl) / 2;
        bool flag = false;
        if (matrix[hm][vm] < target) {
            return dfs(matrix, hm+1, hr, vm+1, vr, target) 
                    || dfs(matrix, hm+1, hr, vl, vm, target)
                    || dfs(matrix, hl, hm, vm+1, vr, target);
        }
        else if (matrix[hm][vm] > target) {
            return dfs(matrix, hl, hm-1, vl, vm-1, target)
                    || dfs(matrix, hm, hr, vl, vm-1, target)
                    || dfs(matrix, hl, hm-1, vm, vr, target);
        }
        else {
            return true;
        }
    }
};