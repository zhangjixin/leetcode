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
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return false;
        ListNode *p(head), *q(head->next->next);
        while (p != q && q != NULL) {
            if (q->next == NULL) return false;
            p = p->next, q = q->next->next;
        }
        return q == NULL ? false : true;
    }
};
