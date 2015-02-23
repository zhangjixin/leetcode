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
        doit(root, NULL);
    }
private:
    void doit(TreeLinkNode *p, TreeLinkNode *q) {
        if (p != NULL) {
            p->next = q;
            doit(p->left, p->right);
            if (q != NULL) {
                doit(p->right, q->left);
                doit(q->left, q->right);
            }
        }
    }
};