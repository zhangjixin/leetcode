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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (m == n) return head;
        int cnt = 1;
        ListNode ans(0), *p = head, *q = head, *pre = &ans;
        ans.next = head;
        while (p != NULL) {
            if (cnt == n)
                return ans.next;
            if (cnt < m) 
                pre = p, p = p->next;
            if (cnt >= m) {
                q = p->next;
                p->next = q->next;
                q->next = pre->next;
                pre->next = q;
            }
            ++cnt;
        }
        return ans.next;
    }
};