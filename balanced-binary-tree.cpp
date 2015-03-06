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
    bool isBalanced(TreeNode *root) {
        bool flag = true;
        if (root != NULL)
            doit (root, flag);
        return flag;
    }
private:
    int doit(TreeNode *root, bool &flag) {
        if (!flag) return 0;
        int left(0), right(0);
        if (root->left != NULL)
            left = doit(root->left, flag);
        if (flag && root->right != NULL)
            right = doit(root->right, flag);
        if (!flag || abs(left - right) > 1) {
            flag = false;
            return 0;
        }
        return 1 + max(left, right);
    }
};