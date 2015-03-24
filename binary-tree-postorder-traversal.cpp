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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ans;
        if (root != NULL)
            doit(root, ans);
        return ans;
    }
private:
    void doit(TreeNode *root, vector<int> &ans) {
        if (root->left != NULL)
            doit(root->left, ans);
        if (root->right != NULL)
            doit(root->right, ans);
        ans.push_back(root->val);
    }
};