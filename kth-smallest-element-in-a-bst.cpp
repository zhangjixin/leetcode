/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int idx = 0;
        return dfs(root, idx, k);
    }
    int dfs(TreeNode *root, int &i, int k) {
        if (root == NULL) return 0;
        int ret = dfs(root->left, i, k);
        if (i == k) return ret;
        if (++i == k)
            return root->val;
        return dfs(root->right, i, k);
    }
};