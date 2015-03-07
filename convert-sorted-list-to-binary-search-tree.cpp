/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        int cnt = 0;
        ListNode *p = head;
        while (p != NULL) {
            ++cnt;
            p = p->next;
        }
        return doit(head, 0, cnt - 1);
    }
private:
    TreeNode *doit(ListNode* &head, int L, int R) {
        if (L > R) return NULL;
        int mid = L + (R - L) / 2;
        TreeNode *left_node = doit(head, L, mid - 1);
        TreeNode *ret = new TreeNode(head->val);
        ret->left = left_node;
        head = head->next;
        ret->right = doit(head, mid+1, R);
        return ret;
    }
};