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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > ans;
        doit(1, root, ans);
        return ans;
    }
private:
    void doit(int k, TreeNode *root, vector<vector<int> > &ans) {
        if (root == NULL) return;
        if (k > ans.size()) {
            ans.push_back(vector<int>());
        }
        ans[k-1].push_back(root->val);
        doit(k+1, root->left, ans);
        doit(k+1, root->right, ans);
    }
};