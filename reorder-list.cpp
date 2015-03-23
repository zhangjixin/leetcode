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
    void reorderList(ListNode *head) {
        if (head == NULL) return;
        ListNode *fast(head), *slow(head), *p(NULL);
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        p = slow->next;
        slow->next = NULL;
        p = P_reverse(p);
        ListNode *cur = head, *next(NULL);
        while (p != NULL) {
            next = cur->next;
            cur->next = p;
            p = p->next;
            cur = cur->next->next = next;
        }
    }
private:
    ListNode *P_reverse(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode *pre(head), *cur(head->next), *next(NULL);
        while (cur != NULL) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        head->next = NULL;
        return pre;
    }
};