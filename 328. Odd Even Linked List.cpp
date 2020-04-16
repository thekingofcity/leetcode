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
    ListNode* oddEvenList(ListNode* head) {
        if(!head||!head->next||!head->next->next) return head;
        auto curOdd = head;
        auto curEven = head->next;
        auto headEven = curEven;
        ListNode* cur = head->next->next;
        while(cur){
            ListNode* tmp=cur->next;
            curOdd->next=cur;
            cur->next=headEven;
            curOdd=cur;
            curEven->next=tmp;
            curEven=tmp;
            if(!tmp) break;
            cur=tmp->next;
        }
        return head;
    }
};