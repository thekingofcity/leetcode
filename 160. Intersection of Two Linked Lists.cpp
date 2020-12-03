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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *A=headA,*B=headB,*lastA=NULL,*lastB=NULL;
        if(A==NULL||B==NULL) return NULL;
        // They may intersect at first
        if(A==B) return A;
        for(;;){
            if(A->next==NULL){
                lastA=A;
                if(lastB){
                    if(lastA!=lastB) return NULL;
                }
                A=headB;
            }else{
                A=A->next;
            }
            if(B->next==NULL){
                lastB=B;
                if(lastA){
                    if(lastA!=lastB) return NULL;
                }
                B=headA;
            }else{
                B=B->next;
            }
            
            if(A==B) return A;
        }
    }
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(nullptr==headA||nullptr==headB) return nullptr;
        ListNode *a=headA, *b=headB;
        bool fa=false, fb=false;
        while(1){
            if(a==b) return a;
            a=a->next;
            if(!a){
                if(!fa){
                    a=headB;
                    fa=true;
                }else
                    return nullptr;
            }
            b=b->next;
            if(!b){
                if(!fb){
                    b=headA;
                    fb=true;
                }else
                    return nullptr;
            }
        }
    }
};
