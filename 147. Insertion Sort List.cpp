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
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode *dummyHead=new ListNode(0);
        dummyHead->next=head;
        ListNode *cur=head,*start=head,*node,*insertCur,*temp;
        while(cur->next!=NULL){
            if(cur->val>cur->next->val){
                node=cur->next;
                cur->next=cur->next->next;
                insertCur=dummyHead;
                while(insertCur!=cur){
                    if(insertCur->next->val>node->val){
                        temp=insertCur->next;
                        insertCur->next=node;
                        node->next=temp;
                        break;
                    }
                    insertCur=insertCur->next;
                }
            }else{
                cur=cur->next;
            }
        }
        return dummyHead->next;
    }
};
/*
[4,2,1,3]
[1]
[1,2]
[2,1]
[]
*/