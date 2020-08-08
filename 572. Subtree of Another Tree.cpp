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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s||!t) return false;
        bool ret=false;
        if(s->val==t->val) ret=helper(s, t);
        bool left = isSubtree(s->left, t);
        bool right = isSubtree(s->right, t);
        return ret||left||right;
    }
    
    bool helper(TreeNode* s, TreeNode* t){
        if(s==nullptr&&t==nullptr) return true;
        if(!s||!t) return false;
        if(s->val!=t->val) return false;
        return helper(s->left, t->left) && helper(s->right, t->right);
    }
};