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
    public ListNode merge(ListNode head1, ListNode head2) {
        if(head1 == null) return head2;
        if(head2 == null) return head1;
        
        ListNode head;
        ListNode ans;
        if(head1.val < head2.val) {
            head = head1;
            ans = head1;
            head1 = head1.next;
        } else {
            head = head2;
            ans = head2;
            head2 = head2.next;
        }
        
        while(head1 != null && head2 != null) {
            if(head1.val < head2.val) {
                head.next = head1;
                head = head1;
                head1 = head1.next;
            } else {
                head.next = head2;
                head = head2;
                head2 = head2.next;
            }
        }
        
        while(head1 != null) {
            head.next = head1;
            head = head1;
            head1 = head1.next;
        }
        
        while(head2 != null) {
            head.next = head2;
            head = head2;
            head2 = head2.next;
        }
        
        return ans;
    }
    public ListNode getMidNode(ListNode head) {
        if(head == null) return head;
        ListNode slow = head;
        ListNode fast = head;
        while(fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode temp = slow.next;
        slow.next = null;
        return temp;
    }
    public ListNode sortList(ListNode head) {
        if(head == null || head.next == null) return head;
        ListNode head1 = head;
        ListNode head2 = getMidNode(head);
        head1 = sortList(head1);
        head2 = sortList(head2);
        return merge(head1, head2);        
    }
}