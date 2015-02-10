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
        ListNode *p = head, *q = head;
        while (p != NULL) {
            while (p->next != NULL && p->next->val == p->val) {
                q = p->next;
                p->next = q->next;
                delete q;
            }
            p = p->next;
        }
        return head;
    }
};