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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) return head;
        ListNode ans(0), *pre = &ans, *cur = head;
        ans.next = head;
        while (cur != NULL) {
            if (cur->val == val) {
                pre->next = cur = cur->next;
            }
            else {
                pre = cur;
                cur = cur->next;
            }
        }
        return ans.next;
    }
};