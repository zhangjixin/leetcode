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
    bool isPalindrome(ListNode* head) {
        return head == NULL || doit(head, head);
    }
    bool doit(ListNode *&head, ListNode *tail) {
        if (tail == NULL) 
            return true;
        bool flag = doit(head, tail->next);
        int val = head->val;
        head = head->next;
        return flag && val == tail->val;
    }
};