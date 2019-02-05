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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode *cur,*next,*dummyHead=new ListNode(head->val-1);
        dummyHead->next=head;
        cur=dummyHead;
        int nextval=0;
        while(cur->next!=NULL){
            nextval=cur->next->val;
            if(cur->next->next!=NULL&&cur->next->next->val==nextval){
                next=cur->next->next;
                while(next->next!=NULL&&next->next->val==nextval) next=next->next;
                cur->next=next->next;
            }else{
                cur=cur->next;
            }
        }
        return dummyHead->next;
    }
};
/*
[1,2,3,3,3,4,4,5]
[1,1,1,2,3]
[]
[1,1]
*/