/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        pushNext(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !NextStack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *nn = NextStack.top();
        NextStack.pop();
        int val = nn->val;
        pushNext(nn->right);
        return val;
    }
private:
    stack<TreeNode *> NextStack;
    void pushNext(TreeNode *root) {
        while (root != NULL) {
            NextStack.push(root);
            root = root->left;
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
