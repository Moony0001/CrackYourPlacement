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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int length = 0;
        ListNode* curr = head;
        while(curr!=nullptr){
            length++;
            curr = curr->next;
        }

        int flips = length/k;

        ListNode* prevtail = new ListNode(-1);
        ListNode* newhead = prevtail;
        ListNode* currhead = new ListNode(-1);
        ListNode* currtail = new ListNode(-1);
        curr = head;
        while(flips>0){
            int temp = k;
            currtail = curr;
            ListNode* prev = nullptr;
            while(temp>0){
                ListNode* tempn = curr->next;
                curr->next = prev;
                prev = curr; 
                currhead = curr;
                curr = tempn;
                temp--;
            }
            prevtail->next = currhead;
            prevtail = currtail;

            flips--;
        }
        currtail->next = curr;
        return newhead->next;
    }
};