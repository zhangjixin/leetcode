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
    int sumNumbers(TreeNode *root) {
        int ans(0);
        if (root != NULL)
            doit(root, 0, ans);
        return ans;
    }
private:
    void doit(TreeNode *root, int k, int &ans) {
        k = k * 10 + root->val;
        if (root->left == root->right) {
            ans += k;
            return;
        }
        if (root->left != NULL)
            doit(root->left, k, ans);
        if (root->right != NULL)
            doit(root->right, k, ans);
    }
};