/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        // ListNode* temp=findMiddleNodeInList(head, NULL);
        // cout<<temp->val<<endl;
        return sortedListToBST(head, NULL);
    }
    
    TreeNode* sortedListToBST(ListNode* head, ListNode* end) {
        TreeNode* root;
        if(head==end){
            return NULL;
        }else if(head->next==end){
            root=new TreeNode(head->val);
            return root;
        }else{
            ListNode* middle=findMiddleNodeInList(head, end);
            root=new TreeNode(middle->val);
            root->left=sortedListToBST(head, middle);
            if(middle->next!=NULL) root->right=sortedListToBST(middle->next, end);
        }
        return root;
    }
    
    ListNode* findMiddleNodeInList(ListNode* head, ListNode* end){
        ListNode* fast=head;
        ListNode* slow=head;
        for(;fast->next!=NULL&&fast->next->next!=NULL&&fast->next!=end&&fast->next->next!=end;fast=fast->next->next)
            slow=slow->next;
        return slow;
    }
};