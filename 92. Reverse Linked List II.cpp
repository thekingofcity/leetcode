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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==n||head==NULL||head->next==NULL) return head;
        ListNode* dummyHead=new ListNode(0);
        dummyHead->next=head;
        ListNode *frontEnd,*current=head,*preCurrent=dummyHead,*postCurrent,*reverseEnd;
        int cur=1;
        while(current){
            if(m>cur){
                preCurrent=current;
                current=current->next;
            }else if(m==cur){
                frontEnd=preCurrent;
                reverseEnd=current;
                preCurrent=current;
                current=current->next;
            }else if(n>cur){
                postCurrent=current->next;
                current->next=preCurrent;
                preCurrent=current;
                current=postCurrent;
            }else if(n==cur){
                frontEnd->next=current;
                postCurrent=current->next;
                current->next=preCurrent;
                reverseEnd->next=postCurrent;
            }else{
                break;
            }
            
            ++cur;
        }
        return dummyHead->next;
    }
};
/*
[1,2,3,4,5]
2
4
[1,2,3,4,5]
1
4
[1,2,3,4,5]
2
5
[1,2,3,4,5]
1
1
[1,2,3,4,5]
5
5
[1,2,3,4,5]
3
3
[1,2,3,4,5]
5
5
*/