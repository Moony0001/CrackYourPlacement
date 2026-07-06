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
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return nullptr;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(ListNode* node : lists){
            while(node!=nullptr){
                pq.push(node->val);
                node = node->next;
            }
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while(!pq.empty()){
            int t = pq.top();
            pq.pop();
            ListNode* temp = new ListNode(t);
            curr->next = temp;
            curr = temp;
        }
        return dummy->next;
    }
};