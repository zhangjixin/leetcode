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
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        int Left = 0, Right = 0;
        TreeNode *p = root;
        while (p != NULL) {
            ++Left, p = p->left;
        }
        p = root;
        while (p != NULL) {
            ++Right, p = p->right;
        }
        if (Left == Right) return (1 << Right) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

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
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        int ans = 0, Left = 0, Right = 0;
        Left = countLevel(root, true);
        Right = countLevel(root, false);
        if(Left == Right) return (1 << Left) - 1;
        int rr = (1 << Right) - 1, ll = 0, mid, tmp;
        vector<bool> flag(Right, 0);
        ans = rr; 
        while (ll <= rr) {
            mid = (ll + rr) >> 1;
            if (doCheck(root, mid, Right - 1))
                ll = mid + 1;
            else
                rr = mid - 1;
        }
        return ans + ll;
    }
    bool doCheck(TreeNode *root, int k, int n) {
        int h = 1 << n;
        while (h) {
            if (k & h) root = root->right;
            else root = root->left;
            h >>= 1;
        }
        return root != NULL;
    }
    int countLevel(TreeNode *root, bool flag) {
        if (root == NULL) return 0;
        return 1 + (flag ? countLevel(root->left, flag) : countLevel(root->right, flag));
    }
};