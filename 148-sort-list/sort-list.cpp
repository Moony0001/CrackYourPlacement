class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        // 1. Get the total length of the linked list
        int len = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            len++;
            curr = curr->next;
        }

        // Dummy node to anchor the start of our list during iterations
        ListNode dummy(0);
        dummy.next = head;

        // 2. Iterate with step sizes: 1, 2, 4, 8, 16...
        for (int step = 1; step < len; step *= 2) {
            ListNode* tail = &dummy;
            curr = dummy.next;
            
            // 3. Process the list in pairs of 'step' size
            while (curr != nullptr) {
                ListNode* left = curr;
                ListNode* right = split(left, step); // Cut out the left chunk
                curr = split(right, step);           // Cut out the right chunk
                
                // Merge the two chunks and attach them to our growing sorted list
                tail = merge(left, right, tail);
            }
        }
        
        return dummy.next;
    }

private:
    // Helper 1: Moves 'step' nodes forward, cuts the list, and returns the remainder
    ListNode* split(ListNode* head, int step) {
        if (head == nullptr) return nullptr;
        
        // Move forward 'step - 1' times to reach the end of the chunk
        for (int i = 1; head->next != nullptr && i < step; i++) {
            head = head->next;
        }
        
        ListNode* right = head->next;
        head->next = nullptr; // Sever the connection!
        
        return right;
    }

    // Helper 2: Merges two lists, attaches to 'tail', and returns the NEW tail
    ListNode* merge(ListNode* l1, ListNode* l2, ListNode* tail) {
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        
        // Attach any remaining nodes
        tail->next = (l1 != nullptr) ? l1 : l2;
        
        // Fast-forward 'tail' to the absolute end of the newly merged section
        while (tail->next != nullptr) {
            tail = tail->next;
        }
        
        return tail;
    }
};