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
    vector<int> ret;
    stack<TreeNode*> s;
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL) return ret;
        s.push(root);
        while(!s.empty()){
            root=s.top();s.pop();
            ret.push_back(root->val);
            if(root->left!=NULL) s.push(root->left);
            if(root->right!=NULL) s.push(root->right);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
/*
[1,null,2,3]
[1,2,3]
[]
*/