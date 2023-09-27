/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        if(head == null) return null;
        Node itr = head;
        while(itr != null) {
            Node temp = new Node(itr.val);
            temp.next = itr.next;
            itr.next = temp;
            itr = itr.next.next;
        }
        
        itr = head;
        while(itr != null) {
            System.out.print(itr.val + "->");
            itr = itr.next;
        }
        Node prev = head;
        itr = head.next;
        while(itr != null) {
            if(prev.random == null) itr.random = null;
            else itr.random = prev.random.next;
            if(itr.next == null) break;
            itr = itr.next.next;
            prev = prev.next.next;
        }
        
        Node ans = head.next;
        itr = head;
        while(itr != null) {
            Node temp = itr.next;
            itr.next = temp.next;
            temp.next = (itr.next == null) ? null : itr.next.next;
            itr = itr.next;
        }
        
        return ans;
    }
}