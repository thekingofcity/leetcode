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
    ListNode* reverseList(ListNode* head) {
        if(nullptr==head) return nullptr;
        ListNode *pre=nullptr, *cur=head, *next=cur->next;
        if(nullptr==next) return head;
        while(next){
            next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        return pre;
    }
};