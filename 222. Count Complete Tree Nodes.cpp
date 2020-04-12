// https://leetcode.com/problems/count-complete-tree-nodes/discuss/62088/My-python-solution-in-O(lgn-*-lgn)-time
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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int left=height(root->left);
        int right=height(root->right);
        if(left==right) return pow(2, left)+countNodes(root->right);
        else return pow(2, right)+countNodes(root->left);
    }
    int height(TreeNode* root) {
        if(!root) return 0;
        return 1+height(root->left);
    }
};