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
    string tree2str(TreeNode* t) {
        string ret="";
        tree2str(t, ret);
        return ret;
    }
    
    void tree2str(TreeNode* t, string &ret) {
        if(nullptr==t) return;
        ret+=to_string(t->val);
        if(nullptr==t->left&&nullptr==t->right) return;
        
        ret+='(';
        tree2str(t->left, ret);
        ret+=')';
        
        if(nullptr==t->right) return;
        ret+='(';
        tree2str(t->right, ret);
        ret+=')';
    }
};