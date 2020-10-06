// Explanation: https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/discuss/366350/C%2B%2B-O(n)-(explained-with-pictures)
// Implementation: Soluiton 2: Two Passes https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/discuss/366319/JavaC%2B%2BPython-Greedily-Skip-with-HashMap
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummyHead = new ListNode(0, head);
        unordered_map<int, ListNode*> m;
        int sum=0;
        for(auto cur=dummyHead;cur;cur=cur->next){
            sum+=cur->val;
            m[sum]=cur;
        }
        sum=0;
        for(auto cur=dummyHead;cur;cur=cur->next){
            sum+=cur->val;
            cur->next=m[sum]->next;
        }
        return dummyHead->next;
    }
};