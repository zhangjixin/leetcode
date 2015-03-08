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
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL) return false;
        return doit(root, sum);
    }
private:
    bool doit(TreeNode *root, int sum) {
        if (root == NULL) return sum == 0;
        if (root->left == NULL && root->right == NULL) 
            return sum == root->val;
        if (root->left == NULL) 
            return doit(root->right, sum - root->val);
        if (root->right == NULL)
            return doit(root->left, sum - root->val);
        return doit(root->left, sum - root->val) || doit(root->right, sum - root->val);
    }
};