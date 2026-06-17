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
    void deleteNode(ListNode* node) {
        int nextval = node->next->val;
        node->val = nextval;
        ListNode *temp = node->next;
        node->next = node->next->next;
        temp->next = nullptr;
    }
};