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
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int left=0,right=0;
        left=minDepth(root->left);
        right=minDepth(root->right);
        if(left==0&&right!=0){
            return right+1;
        }else if(left!=0&&right==0){
            return left+1;
        }else if(left==0&&right==0){
            return 1;
        }else{
            return min(left, right) + 1;
        }
    }
};