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
    ListNode *sortList(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *mid(head), *right(head), *left(head);
        mid = split_List(head);
        right = sortList(mid->next);
        mid->next = NULL;
        left = sortList(head);
        return merge_List(left, right);
    }
private:
    ListNode *split_List(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode *merge_List(ListNode *one, ListNode *two) {
        ListNode ans(0), *p = &ans;
        while (one != NULL && two != NULL) {
            if (one->val > two->val) {
                p->next = two;
                two = two->next;
            }
            else {
                p->next = one;
                one = one->next;
            }
            p = p->next;
        }
        p->next = (one == NULL ? two : one);
        return ans.next;
    }
};
