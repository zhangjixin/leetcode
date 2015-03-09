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
    void flatten(TreeNode *root) {
        TreeNode *p(NULL);
        doit(root, p);
    }
private:
    void doit(TreeNode *root, TreeNode *&p) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) {
            p = root;
            return;
        }
        if (root->left != NULL)
            doit(root->left, p);
        if (p != NULL) {
            p->right = root->right;
            root->right = root->left;
            root->left = NULL;
            TreeNode *q = p;
            if (p->right != NULL) {
                p = NULL;
                doit(q->right, p);
            }
        } else if (root->right != NULL){
            doit(root->right, p);
        }
    }
};