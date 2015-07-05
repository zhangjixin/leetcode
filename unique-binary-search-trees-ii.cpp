/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #define VTN vector<TreeNode*>
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return *generate(1, n);
    }
    VTN *generate(int L, int R) {
       VTN *ret = new VTN();
       if (L > R) {
           ret->push_back(NULL);
           return ret;
       }
       for (int i = L; i <= R; ++i) {
           VTN *treeL = generate(L, i-1);
           VTN *treeR = generate(i+1, R);
           for (int j = 0,jl = (*treeL).size(); j < jl; ++j)
           for (int k = 0, kl = (*treeR).size(); k < kl; ++k) {
               TreeNode *root = new TreeNode(i);
               root->left = (*treeL)[j];
               root->right = (*treeR)[k];
               ret->push_back(root);
           }
       }
       return ret;
    }
};