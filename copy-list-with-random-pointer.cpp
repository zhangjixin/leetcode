/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode ans(0), *p = head, *pre = &ans, *q = head;
        while (p != NULL) {
            RandomListNode *newNode = new RandomListNode(p->label);
            q = p->next;
            p->next = newNode;
            newNode->next = q;
            p = q;
        }
        p = head;
        while (p != NULL) {
            if (p->random != NULL) {
                p->next->random = p->random->next;
            } else {
                p->next->random = NULL;
            }
            p = p->next->next;
        }
        p = head;
        while (p != NULL) {
            pre->next = p->next;
            pre = pre->next;
            p->next = pre->next;
            p = p->next;
        }
        return ans.next;
    }
};
