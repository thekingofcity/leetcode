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
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummyLessHead=new ListNode(0);
        ListNode *dummyMoreHead=new ListNode(0);
        ListNode *less=dummyLessHead,*more=dummyMoreHead,*cur=head;
        while(cur){
            if(cur->val<x){
                less->next=cur;
                less=less->next;
            }else{
                more->next=cur;
                more=more->next;
            }
            cur=cur->next;
        }
        less->next=dummyMoreHead->next;
        more->next=NULL;
        return dummyLessHead->next;
    }
};