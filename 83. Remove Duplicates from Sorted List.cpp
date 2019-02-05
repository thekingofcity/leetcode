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
        ListNode *cur=head;
        while(cur->next!=NULL){
            if(cur->val==cur->next->val){
                cur->next=cur->next->next;
            }else{
                cur=cur->next;
            }
        }
        return head;
    }
};
/*
[1,1,2]
[1,1,2,3,3]
[1]
[]
[1,1,1]
[1,1,1,1]
[0,1,1,1,2]
[1,2,2]
*/