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
private:
    unsigned long len=0;
    ListNode* h;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        h=head;
        auto cur=h;
        len=0;
        while(cur){
            cur=cur->next;
            len++;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int r=rand()%len;
        auto cur=h;
        while(r>0){
            cur=cur->next;
            r--;
        }
        return cur->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */