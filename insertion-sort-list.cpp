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
    ListNode *insertionSortList(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode ans(INT_MIN), *p = head, *q = NULL, *h = &ans;
        ans.next = head;
        while (p->next != NULL) {
            if (p->val > p->next->val) {
                q = p->next;
                p->next = q->next;
                h = &ans;
                while (h != p) {
                    if (h->val <= q->val && h->next->val > q->val) {
                        q->next = h->next;
                        h->next = q;
                        break;
                    }
                    h = h->next;
                }
            }
            else {
                p = p->next;
            }
        }
        return ans.next;
    }
};