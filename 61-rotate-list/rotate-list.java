/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        //Check Notes for more

        if(head==null){
            return head;
        }

        ListNode trav = head;
        int len = 0;
        while(trav!=null){
            len++;
            trav = trav.next;
        }

        k =  k%len;
        if(k==0){
            return head;
        }
        ListNode newHead = head;
        int i=1;
        while(i<(len-k)){
            newHead = newHead.next;
            i++;
        }
        ListNode temp = newHead.next;
        newHead.next = null;
        newHead = temp;
        ListNode last = newHead;
        while(last.next!=null){
            last = last.next;
        }
        last.next = head;
        return newHead;
        // ListNode left = new ListNode();
        // ListNode right = new ListNode();
        // left = head;
        // right = head;
        // while(k>0){
        //     if(k>0 && right.next == null){
        //         right = head;
        //         k--;
        //     }else{
        //         right = right.next;
        //         k--;
        //     }
        // }
        // while(right.next != null){
        //     left = left.next;
        //     right = right.next;
        // }
        // right.next = head;
        // head = left.next;
        // left.next = null;
        // return head;
    }
}