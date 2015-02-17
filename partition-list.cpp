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
    ListNode *partition(ListNode *head, int x) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *p = head, *q = NULL, *k = NULL, *ans = NULL;
        head = NULL;
        while (p != NULL) {
            if (p->val < x) {
                k == NULL ? ans = k = p : k = k->next = p;
                if (q != NULL) {
                    q->next = p->next;
                }
            }
            else {
                q == NULL ? head = q = p : q = q->next;
            }
            p = p->next;
        }
        if (ans == NULL) return head;
        k->next = head;
        if (q != NULL ) q->next = NULL;
        return ans;
    }
};