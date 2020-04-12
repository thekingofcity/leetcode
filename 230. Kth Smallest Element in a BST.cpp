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
    int ret=INT_MAX;
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root->left&&!root->right) return root->val;
        _kthSmallest(root, k, 0);
        return ret;
    }
    int _kthSmallest(TreeNode* root, int k, int c) {
        if(c>=k) return c;
        if(!root) return c;
        if(!root->left&&!root->right) return c+1;
        
        c=_kthSmallest(root->left, k, c);
        if(c==k){
            ret=root->left->val;
            return c+1;
        }
        
        c++;  // +1 for root
        if(c==k){
            ret=root->val;
            return c+1;
        }
        
        c=_kthSmallest(root->right, k, c);
        if(c==k){
            ret=root->right->val;
            return c+1;
        }
        return c;
    }
};
// [3,1,4,null,2]
// 1
// [5,3,6,2,4,null,null,1]
// 3
// [5,3,6,2,4,null,null,1]
// 5
// [5,3,6,2,4,null,null,1]
// 6
// [1]
// 1
// [2,1]
// 2
// [2,1]
// 1
// [2,1,3]
// 2
// [2,1,3]
// 3
// [3,1,4,null,2]
// 2