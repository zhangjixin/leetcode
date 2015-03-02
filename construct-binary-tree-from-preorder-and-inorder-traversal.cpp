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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return doit(0, preorder.size(), 0, preorder, inorder);
    }
private:
    TreeNode *doit(int i, int leni, int j, vector<int> &pre, vector<int> &mid) {
        if (leni == 0) return NULL;
        int k(j);
        TreeNode *root = new TreeNode(pre[i]);
        while (pre[i] != mid[k]) ++k;
        root->left = doit(i + 1, k - j, j, pre, mid);
        root->right = doit(i + k - j + 1, leni - (k - j + 1), k + 1, pre, mid);
        return root;
    }
};