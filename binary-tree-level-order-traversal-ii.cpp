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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > ans, ret;
        if (root != NULL)
            doit(1, root, ret);
        for (int i = ret.size() - 1; i >= 0; --i)
            ans.push_back(ret[i]);
        return ans;
    }
private:
    void doit(int k, TreeNode *root, vector<vector<int> > &ans) {
        if (ans.size() < k) {
            ans.push_back(vector<int>());
        }
        ans[k-1].push_back(root->val);
        if (root->left != NULL) 
            doit(k+1, root->left, ans);
        if (root->right != NULL) 
            doit(k+1, root->right, ans);
    }
};