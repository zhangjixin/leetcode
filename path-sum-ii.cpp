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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > ans;
        vector<int> vec;
        if (root != NULL) 
            doit(root, sum, ans, vec);
        return ans;
    }
private:
    void doit(TreeNode *root, int sum, vector<vector<int> > &ans, vector<int> &vec) {
        vec.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            if (root->val == sum) ans.push_back(vec);
            vec.pop_back();
            return;
        }
        if (root->left != NULL) 
            doit(root->left, sum - root->val, ans, vec);
        if (root->right != NULL)
            doit(root->right, sum - root->val, ans, vec);
        vec.pop_back();
    }
};