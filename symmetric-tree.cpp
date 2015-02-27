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
    bool isSymmetric(TreeNode *root) {
        if (root == NULL) return true;
        return doit(root->left, root->right);
    }
private:
    bool doit(TreeNode *p, TreeNode *q) {
        if (p == NULL || q == NULL) 
            return p == q;
        if (p->val != q->val) 
            return false;
        return doit(p->left, q->right) && doit(p->right, q->left);
    }
};