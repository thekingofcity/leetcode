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
    ListNode* removeElements(ListNode* head, int val) {
        while(head&&head->val==val){
            if(!head->next) return NULL;
            head=head->next;
        }
        ListNode* cur=head;
        while(cur&&cur->next){
            if(cur->next->val==val){
                if(cur->next->next) cur->next=cur->next->next;
                else cur->next=NULL;
            }else
                cur=cur->next;
        }
        return head;
    }
};