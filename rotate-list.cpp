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
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL || head->next == NULL || k == 0) return head;
        ListNode *p = head;
        int cnt = 1;
        while (p->next != NULL) {
            ++cnt;
            p = p->next;
        }
        k %= cnt;
        if (k == 0) return head;
        p->next = head, p = head;
        for (int i = 1; i < cnt-k; ++i) {
            p = p->next;
        }
        head = p->next, p->next = NULL;
        return head;
    }
};