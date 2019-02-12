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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0||inorder.size()==0||preorder.size()!=inorder.size())
            return NULL;
        return buildTree(preorder, inorder, 0, 0, inorder.size()-1);
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder,
                        int preorderIndex,
                        int inorderStart, int inorderEnd) {
        if(inorderStart>inorderEnd) return NULL;
        TreeNode *root=new TreeNode(preorder[preorderIndex]);
        
        // if there is only one val, then it is the leaf
        if(inorderStart==inorderEnd) return root;
        
        // find root->val's index in inorder
        int inorderIndex=inorderStart;
        for(;inorderIndex<=inorderEnd;++inorderIndex)
            if(inorder[inorderIndex]==preorder[preorderIndex])
                break;
        
        // calculate left/right side size
        int leftSize=inorderIndex-inorderStart,rightSize=inorderEnd-inorderIndex;
        if(leftSize>0){
            root->left=buildTree(preorder, inorder, preorderIndex+1,
                                 inorderStart, inorderIndex-1);
        }
        if(rightSize>0){
            root->right=buildTree(preorder, inorder, preorderIndex+leftSize+1,
                                 inorderIndex+1, inorderEnd);
        }
        
        return root;
    }
};