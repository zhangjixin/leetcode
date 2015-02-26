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
    bool isValidBST(TreeNode *root) {
        if (root == NULL) return true;
        int preval = INT_MIN, ans = 1;
        doit(root, preval, ans);
        return ans;
    }
private:
    void doit(TreeNode *root, int &preval, int &ans) {
        if (ans == 0) return;
        if (root->left != NULL)
            doit(root->left, preval, ans);
        if (ans == 1) {
            preval = root->val, ans = 2;
        }
        else if (preval >= root->val) {
            ans = 0;
            return;
        }
        preval = root->val;
        if (root->right != NULL)
            doit(root->right, preval, ans);
    }
};