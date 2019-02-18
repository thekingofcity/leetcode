/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head==NULL) return NULL;
        RandomListNode *cur=head;
        while(cur){
            RandomListNode *curCopy=new RandomListNode(cur->label);
            curCopy->next=cur->next;
            cur->next=curCopy;
            cur=curCopy->next;
        }
        cur=head;
        while(cur){
            if(cur->random) cur->next->random = cur->random->next;
            cur = cur->next->next;
        }
        cur=head;
        RandomListNode *ret=head->next,*tmp;
        while(cur){
            tmp=cur->next;
            cur->next=tmp->next;
            if(tmp->next) tmp->next=tmp->next->next;
            cur=cur->next;
        }
        return ret;
    }
};