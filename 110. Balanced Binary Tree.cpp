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
    bool isBalanced(TreeNode* root) {
        if(isBalancedCode(root)==-1) return false;
        return true;
    }
    
    int isBalancedCode(TreeNode* root){
        if(root==NULL) return 0;
        int left=isBalancedCode(root->left)+1;
        if(left==0) return -1;
        int right=isBalancedCode(root->right)+1;
        if(right==0) return -1;
        if(abs(left-right)>1) return -1;
        return max(left, right);
    }
};
/*
[3,9,20,null,null,15,7]
[1,2,2,3,3,null,null,4,4]
[1,2,2,3,null,null,3,4,null,null,4]
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(helper(root)==-1) return false;
        return true;
    }
    
    int helper(TreeNode* root){
        if(!root) return 0;
        int left=helper(root->left);
        int right=helper(root->right);
        if(left<0||right<0) return -1;
        if(abs(left-right)>1) return -1;
        return max(left, right)+1;
    }
};