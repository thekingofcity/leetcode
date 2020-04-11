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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        if(root->left||root->right){
            invertTree(root->left);
            invertTree(root->right);
            swap(root);
        }
        return root;
    }
        
    void swap(TreeNode* root) {
        TreeNode* tmp;
        tmp=root->left;
        root->left=root->right;
        root->right=tmp;
    }
};