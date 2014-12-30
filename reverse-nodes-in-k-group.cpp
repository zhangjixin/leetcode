/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(head == NULL) return head;
        ListNode *p[k], *q;
        p[0] = head;
        for(int i = 1; i < k; ++i) {
            p[i] = p[i-1]->next;
            if(p[i] == NULL) return head;
        }
        q = p[k-1]->next;
        for(int i = k-1; i > 0; --i){
            p[i]->next = p[i-1];
        }
        p[0]->next=reverseKGroup(q, k);
        return p[k-1];
    }
};
*/
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
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode ans(0);
        ans.next = head;
        ListNode *pre = &ans, *p = head, *begin = head, *end = head;
        for(p = head; p != NULL; p = p->next) {
            begin = end = p;
            for(int i = 0; i < k-1 && end; ++i) {
                end = end->next;
            }
            if(end == NULL) break;
            p = pre = doit(pre, begin, end);
        }
        return ans.next;
    }
private:
    ListNode *doit(ListNode *pre, ListNode *begin, ListNode *end) {
        ListNode *endp = end->next;
        ListNode *nextp = begin, *curp = begin->next, *prep;
        while(curp != endp) {
            prep = curp->next, curp->next = nextp, nextp = curp, curp = prep;
        }
        pre->next = end, begin->next = endp;
        return begin;
    }
};