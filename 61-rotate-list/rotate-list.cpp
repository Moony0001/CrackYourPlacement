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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr) return head;
        int length = 0;
        ListNode* curr = head;
        while(curr!=nullptr){
            length++;
            curr = curr->next;
        }
        k = k%length;
        ListNode* tail = head;
        ListNode* newtail = head;
        int temp = k;
        while(temp>0){
            tail = tail->next;
            temp--;
        }

        while(tail->next!=nullptr){
            tail = tail->next;
            newtail = newtail->next;
        }

        tail->next = head;
        head = newtail->next;
        newtail->next = nullptr;
        return head;
    }
};