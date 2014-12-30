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
    ListNode *swapPairs(ListNode *head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode ans(0);
        ListNode *p = head, *q = head->next, *pre = &ans;
        while(q != NULL) {
            p->next = q->next, q->next = p, pre->next = q;
            pre = p, p = p->next;
            if(p != NULL) {
                q = p->next;
            }else{
                break;
            }
        }
        return ans.next;
    }
};