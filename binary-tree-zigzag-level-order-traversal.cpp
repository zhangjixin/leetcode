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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > ans;
        if (root != NULL) 
            doit(1, root, ans);
        for (int i = 0; i < ans.size(); ++i) {
            if (i&1) {
                reverse(ans[i].begin(), ans[i].end());
            }
        }
        return ans;
    }
private:
    void doit(int k, TreeNode *root, vector<vector<int> > &ans) {
        if (k > ans.size()) {
            ans.push_back(vector<int>());
        }
        ans[k-1].push_back(root->val);
        if (root->left != NULL)
            doit(k+1, root->left, ans);
        if (root->right != NULL) 
            doit(k+1, root->right, ans);
    }
};