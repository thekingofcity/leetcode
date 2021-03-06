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

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(nullptr==head) return nullptr;
        Node* cur=head;
        while(cur){
            Node* curCopy=new Node(cur->val);
            curCopy->next=cur->next;
            cur->next=curCopy;
            cur=cur->next->next;
        }
        cur=head;
        while(cur){
            if(cur->random){
                cur->next->random=cur->random->next;
            }
            cur=cur->next->next;
        }
        cur=head;
        Node* ret=cur->next,*curRet=ret;
        while(cur){
            Node* tmp=cur->next;
            cur->next=tmp->next;
            if(tmp->next) tmp->next=tmp->next->next;
            cur=cur->next;
        }
        return ret;
    }
};