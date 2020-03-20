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
private:
    int __ = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        helper(root);
        return __;
    }
    
    int helper(TreeNode* root) {
        long left=INT_MIN,right=INT_MIN;
        if(root->left) left=helper(root->left);
        if(root->right) right=helper(root->right);
        
        long m=root->val,n=root->val+left,p=root->val+right,q=root->val+left+right;
        int _ = max(max(max(m, n), p), q);
        // printf("%d %d %d\n%d %d %d %d %d\n", root->val, left, right, m, n, p, q, _);
        __ = max(_, __);
        
        return max(max(m,n), p);
    }
};