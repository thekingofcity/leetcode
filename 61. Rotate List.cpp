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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL) return head;
        int l=0,count=1;
        ListNode* cur=head,*end,*temp;
        while(cur!=NULL){
            end=cur;
            cur=cur->next;
            ++l;
        }
        k=k%l;
        if(k==0) return head;
        cur=head;
        while(count<l-k){
            ++count;
            cur=cur->next;
        }
        temp=cur->next;
        cur->next=NULL;
        end->next=head;
        return temp;
    }
};
/*
[1,2,3,4,5]
2
[0,1,2]
4
[]
0
[1]
1
[1]
99
[1,2]
2
[1,2]
1
*/