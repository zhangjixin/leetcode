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
    ListNode *detectCycle(ListNode *head) {
        ListNode *p = head, *q = head;
        bool flag(true);
        while (p != NULL) {
            if (flag && (p = p->next) == NULL) {
                return NULL;
            }
            p = p->next;
            q = q->next;
            if (p == q) {
                if (flag) {
                    q = head;
                    if (p == q) return p;
                    flag = false;
                } else {
                    return p;
                }
            }
        }
        return NULL;
    }
};
