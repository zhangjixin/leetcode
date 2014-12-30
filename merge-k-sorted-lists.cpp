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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int i = 0;
        
        while(i < lists.size()) {
            if(lists[i] == NULL) {
                lists.erase(lists.begin()+i);
            }else {
                ++i;
            }
        }
        ListNode head(0);
        ListNode *p = &head;
        int MIN = INT_MAX, flag = 0, len = lists.size();
        Node nn(0,0);
        
        for(i = 0; i < len; ++i) que.push(Node(i, lists[i]->val));
        
        while(!que.empty()) {
            nn = que.top();
            que.pop();
            p->next = lists[nn.dex], p = p->next;
            if((lists[nn.dex] = lists[nn.dex]->next) != NULL) {
                que.push(Node(nn.dex, lists[nn.dex]->val));
            }
        }
        
        p->next = NULL;
        return head.next;
    }
private:
    struct Node{
        int dex, val;
        Node(int x, int y): dex(x), val(y) {}
        bool operator< (const Node &nn)const {
            return val > nn.val;
        }
    };
    priority_queue<Node> que;
};