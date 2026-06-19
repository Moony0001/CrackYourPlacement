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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* trav1 = l1;
        ListNode* trav2 = l2;
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while(trav1!=nullptr && trav2!=nullptr){
            int data = trav1->val+trav2->val+carry;
            ListNode* temp = new ListNode();
            temp->val = data%10;
            curr->next = temp;
            curr = curr->next;
            carry = data/10;
            trav1 = trav1->next;
            trav2 = trav2->next;
        }

        if(trav2!=nullptr){
            while(trav2!=nullptr){
                int data = trav2->val+carry;
                ListNode* temp = new ListNode();
                temp->val = data%10;
                curr->next = temp;
                curr = curr->next;
                carry = data/10;
                trav2 = trav2->next;
            }
        }else if(trav1!=nullptr){
            while(trav1!=nullptr){
                int data = trav1->val+carry;
                ListNode* temp = new ListNode();
                temp->val = data%10;
                curr->next = temp;
                curr = curr->next;
                carry = data/10;
                trav1 = trav1->next;
            }
        }

        if(carry){
            ListNode* newtemp = new ListNode(carry);
            curr->next = newtemp;
        }

        return dummy->next;
    }
};