/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct CompareNode{
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return nullptr;

        priority_queue<ListNode*, vector<ListNode*>, CompareNode> pq;

        for(ListNode* node : lists){
            if(node!=nullptr){
                pq.push(node);
            }
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        while(!pq.empty()){
            ListNode* t = pq.top();
            pq.pop();
            
            curr->next = t;
            curr = curr->next;
            if(t->next != nullptr){
                pq.push(t->next);
            }
        }
        ListNode* head = dummy->next;
        delete dummy;
        return head;
    }
};