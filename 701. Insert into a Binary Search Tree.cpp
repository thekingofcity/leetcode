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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        TreeNode* ret=root;
        while(true){
            if(val<root->val){
                if(root->left) root=root->left;
                else break;
            }else{
                if(root->right) root=root->right;
                else break;
            }
        }
        if(val<root->val) root->left=new TreeNode(val);
        else root->right=new TreeNode(val);
        return ret;
    }
};