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
    void recoverTree(TreeNode *root) {
        vector<TreeNode *> vec(3, NULL);
        doit(root, vec);
        swap(vec[0]->val, vec[1]->val);
    }
private:
    void doit(TreeNode *root, vector<TreeNode *> &vec) {
        if (root->left != NULL) doit(root->left, vec);
        if (vec[2] != NULL && vec[2]->val > root->val) {
            if (vec[0] == NULL) vec[0] = vec[2];
            vec[1] = root;
        }
        vec[2] = root;
        if (root->right != NULL) doit(root->right, vec);
    }
};