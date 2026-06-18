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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        ListNode* revhead = nullptr;
        bool flag = false;
        while(fast!=nullptr && fast->next!=nullptr){
            fast = fast->next->next;
            if(fast==nullptr){
                flag = true;
            }
            ListNode* temp = slow->next;
            slow->next = prev;
            prev = slow;
            revhead = slow;
            slow = temp;
        }
        if(!flag){
            slow = slow->next;   
        }
        while(revhead!=nullptr && slow!=nullptr){
            if(revhead->val!=slow->val){
                return false;
            }
            revhead = revhead->next;
            slow = slow->next;
        }
        
        return true;
    }
};