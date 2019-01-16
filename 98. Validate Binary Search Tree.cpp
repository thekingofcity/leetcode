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
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        return isValidBST(root, NULL, NULL);
    }
    
    bool isValidBST(TreeNode* root, TreeNode* left_limit, TreeNode* right_limit) {
        // cout<<root->val<<" "<<left_limit<<" "<<right_limit<<endl;
        if(left_limit&&root->val<=left_limit->val) return false;
        if(right_limit&&root->val>=right_limit->val) return false;
        if(root->left!=NULL){
            bool left = isValidBST(root->left, left_limit, root);
            if(!left) return false;
        }
        if(root->right!=NULL){
            bool right = isValidBST(root->right, root, right_limit);
            if(!right) return false;
        }
        return true;
    }
};
/*
https://leetcode.com/problems/validate-binary-search-tree/discuss/32141/C%2B%2B-simple-recursive-solution
[2,1,3]
[5,1,4,null,null,3,6]
[10,5,15,null,null,6,20]
[1,1]
here is buggy INT_MAX, INT_MIN
[2147483647]
[0,null,-1]
[]
*/