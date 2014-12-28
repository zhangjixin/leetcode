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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *p , *q, *t;
        int cnt = 1;
        p = q = t = head;
        
        while(q != NULL) {
            if(cnt <= n) {
                q = q->next;
                ++cnt;
            }else{
                t = p;
                p = p->next;
                q = q->next;
            }
        }
        
        if(p == head) {
            head = head->next;
            delete p;
            return head;
        }
        t->next = p->next;
        delete p;
        return head;
    }
};