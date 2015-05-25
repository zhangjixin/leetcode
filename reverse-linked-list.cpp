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
    ListNode* reverseList(ListNode* head) {
        ListNode ans(0), *cur = head, *next = NULL;
        while (cur != NULL) {
            next = cur->next;
            cur->next = ans.next;
            ans.next = cur;
            cur = next;
        }
        return ans.next;
    }
};