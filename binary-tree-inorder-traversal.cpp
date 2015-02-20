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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ans;
        doit(root, ans);
        return ans;
    }
private:
    void doit(TreeNode *root, vector<int> &ans) {
        if (root == NULL) return;
        doit(root->left, ans);
        ans.push_back(root->val);
        doit(root->right, ans);
    }
};