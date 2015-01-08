/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode ans(0), *pre = &ans, *p = head, *q;
        ans.next = head;
        while (p != NULL) {
            q = p->next;
            while (q != NULL && q->val == p->val) q = q->next;
            if (p->next != q) {
                pre->next = q;
                p = q;
            } else {
                pre = p;
                p = q;
            }
        }
        return ans.next;
    }
};
