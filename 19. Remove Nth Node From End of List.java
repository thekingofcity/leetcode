/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        
        // deal with [1] 1
        if(head.next==null && n==1){return null;}
        // deal with [1,2] 1
        if(head.next.next==null && n==1){head.next = null;return head;}
        
        ListNode fastNode = head;
        ListNode slowNode = head;
        
        for(int i=0;i<n-2;i++){
            fastNode = fastNode.next;
        }
        
        System.out.println(fastNode.val);
        System.out.println();
        
        // get node 3 not 4, though node 4 is what we want to delete
        if (fastNode.next.next == null){
            // deal with n == list.length, pop the first one
            return head.next;
        }else{
            fastNode = fastNode.next;
            fastNode = fastNode.next;
        }
        
        System.out.print(fastNode.val + " " + slowNode.val + "\n");
        
        while(fastNode.next != null){
            fastNode = fastNode.next;
            slowNode = slowNode.next;
            
        System.out.print(fastNode.val + " " + slowNode.val + "\n");
        
        }
        
        if(n!=1){
            slowNode.next = slowNode.next.next;
        }else{
            slowNode.next.next = null;
        }
        
        return head;
    }
}