/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *k(root);
        while (k != NULL) {
            TreeLinkNode next(0);
            for (TreeLinkNode *p = k, *pre = &next; p != NULL; p = p->next) {
                if (p->left != NULL) {
                    pre->next = p->left, pre= pre->next;
                }
                if (p->right != NULL) {
                    pre->next = p->right; pre = pre->next;
                }
            }
            k = next.next;
        }
    }
};
