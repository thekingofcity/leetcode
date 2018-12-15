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
    ListNode* swapPairs(ListNode* head) {
        int index=0;
        ListNode dummyHead = {0};
        dummyHead.next=head;
        ListNode dummyHead_ = {0};
        dummyHead_.next=&dummyHead;
        ListNode * cur_next,* temp;
        ListNode * cur = dummyHead.next;
        ListNode * cur_prev = &dummyHead;
        ListNode * cur_prev_prev = &dummyHead_;
        while(cur!=NULL){
            index++;
            if(index%2==0){
                cur_next=cur->next;
                cur_prev_prev->next=cur;
                cur->next=cur_prev;
                cur_prev->next=cur_next;
                
                // change cu,cur_prev to there definition
                temp=cur;
                cur=cur_prev;
                cur_prev=temp;
            }
            // go to next one
            cur_prev_prev=cur_prev;
            cur_prev=cur;
            cur=cur->next;
        }
        return dummyHead.next;
    }
};