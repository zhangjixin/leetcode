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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return doit(postorder.size() - 1, postorder.size(), 0, postorder, inorder);
    }
private:
    TreeNode *doit(int i, int leni, int j, vector<int> &post, vector<int> &mid) {
        if (leni == 0) return NULL;
        int k(j);
        TreeNode *root = new TreeNode(post[i]);
        while (post[i] != mid[k]) ++k;
        root->left = doit(i - (leni - (k - j)), k - j, j, post, mid);
        root->right = doit(i - 1, leni - (k - j + 1), k + 1, post, mid);
        return root;
    }
};