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
    int maxPathSum(TreeNode *root) {
        int ans(root->val);
        doit(root, ans);
        return ans;
    }
private:
    int doit(TreeNode *root, int &ans) {
        if (root == NULL) return 0;
        ans = max(ans, root->val);
        if (root->left == NULL && root->right == NULL) {
            return root->val;
        }
        int left = doit(root->left, ans);
        int right = doit(root->right, ans);
        ans = max(ans, left + right + root->val);
        ans = max(ans, root->val + max(left, right));
        return max(root->val, root->val + max(left, right));
    }
};
