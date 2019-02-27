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
    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* mid=split(head);
        head=sortList(head);
            // cout<<"a";printList(head);
        mid=sortList(mid);
            // cout<<"b";printList(mid);
        ListNode* ret=merge(head, mid);
            // cout<<"head";printList(ret);
        return ret;
    }
    ListNode* split(ListNode* head){
        ListNode *fast=head,*slow=head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode *anotherHalf=slow->next;
        slow->next=NULL;
        return anotherHalf;
    }
    ListNode* merge(ListNode* listA, ListNode* listB){
        ListNode *a=listA,*b=listB,*cur,*head;
        if(a->val<b->val){
            head=a;
            a=a->next;
        }else{
            head=b;
            b=b->next;
        }
        cur=head;
        while(a&&b){
            if(a->val<b->val){
                cur->next=a;
                cur=cur->next;
                a=a->next;
            }else{
                cur->next=b;
                cur=cur->next;
                b=b->next;
            }
        }
        if(a) cur->next=a;
        if(b) cur->next=b;
        return head;
    }
    void printList(ListNode* cur){
        while(cur){
            cout<<cur->val;
            cur=cur->next;
        }
        cout<<endl;
        return;
    }
};