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
    bool hasCycle(ListNode *head) {
        ListNode *A=head,*B=head;
        if(head==NULL) return false;
        for(;;){
            if(A->next==NULL){
                return false;
            }else{
                A=A->next;
            }
            if(B->next==NULL||B->next->next==NULL){
                return false;
            }else{
                B=B->next->next;
            }
            
            if(A==B) return true;
        }
    }
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL) return false;
        ListNode *slow=head,*fast=head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow) return true;
        }
        return false;
    }
};

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
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode *fast=head,*slow=head;
        while(fast->next&&fast->next->next&&slow->next){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow) return true;
        }
        return false;
    }
};