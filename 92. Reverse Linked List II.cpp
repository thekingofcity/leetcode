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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head||m==n) return head;
        bool first=false;
        if(m==1){
            first=true;
            head=new ListNode(-1, head);
            ++m; ++n;
        }
        
        ListNode *pre,*cur=head,*leftEnd=head,*revEnd,*tmp;
        int c=1;
        while(cur){
            if(c==m){
                revEnd=cur;
                leftEnd=pre;
                pre=cur;
                tmp=cur->next;
                cur->next=NULL;
                cur=tmp;
            }else if(c>m&&c<=n){
                tmp=cur->next;
                cur->next=pre;
                pre=cur;
                cur=tmp;
            }else if(c>n){
                revEnd->next=cur;
                leftEnd->next=pre;
                break;
            }else{
                pre=cur;
                cur=cur->next;
            }
            ++c;
        }
        if(c==n+1) leftEnd->next=pre;
        
        if(first) return head->next;
        return head;
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
1
5
[1,2,3,4,5]
2
5
[1,2,3,4,5]
3
3
*/