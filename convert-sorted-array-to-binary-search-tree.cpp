/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return doit(num, 0, num.size() - 1);
    }
private:
    TreeNode *doit(const vector<int> &num, int L, int R) {
        if (L > R) return NULL;
        int mid = L + (R - L) / 2;
        TreeNode *ret = new TreeNode(num[mid]);
        ret->left = doit(num, L, mid - 1);
        ret->right = doit(num, mid + 1, R);
        return ret;
    }
};