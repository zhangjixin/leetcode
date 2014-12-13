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
    int rem = 0, sum = 0;

    int getVal(ListNode *p){
        if(p != NULL)
            return p->val;
        return 0;
    }
    ListNode *newNode(ListNode *p, ListNode *q) {
        sum = rem;
        sum += getVal(p);
        sum += getVal(q);
        ListNode *nn = new ListNode(sum%10);
        rem = sum / 10;
        return nn;
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

        struct ListNode *head = NULL;
        struct ListNode *p , *q;
        if( (l1 != NULL) && (l2 != NULL)){
            head = newNode(l1,l2);
            l1 = l1->next;
            l2 = l2->next;
        }else{
            return l1==NULL?l2:l1;
        }
        p = head;
        while ( (l1 != NULL) && (l2 != NULL)) {
            q = newNode(l1, l2);
            p->next = q;
            p = q;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL) {
            q = newNode(l1, NULL);
            p->next = q;
            p = q;
            l1 = l1->next;
        }
        while(l2 != NULL) {
            q = newNode(NULL, l2);
            p->next = q;
            p = q;
            l2 = l2->next;
        }
        if(rem != 0) {
            q = new ListNode(rem);
            p->next = q;
        }
        return head;
    }
};