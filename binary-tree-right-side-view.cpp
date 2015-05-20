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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;
        find_ans(root, 0, ans);
        return ans;
    }
    void find_ans(TreeNode *root, int depth, vector<int> &ans) {
        if (root == NULL) return;
        if (depth == ans.size()) {
            ans.push_back(root->val);
        }
        find_ans(root->right, depth+1, ans);
        find_ans(root->left, depth+1, ans);
    }
};