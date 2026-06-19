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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curra = headA;
        ListNode* currb = headB;

        while(curra!=nullptr && currb!=nullptr){
            if(curra==currb) return curra;
            curra = curra->next;
            currb = currb->next;
        }

        if(curra==nullptr){
            curra = headB;
            while(currb!=nullptr){
                curra = curra->next;
                currb = currb->next;
            }
            currb = headA;
        }else if(currb==nullptr){
            currb = headA;
            while(curra!=nullptr){
                curra = curra->next;
                currb = currb->next;
            }
            curra = headB;
        }

        while(curra!=currb){
            curra = curra->next;
            currb = currb->next;
        }
        return curra;
    }
};