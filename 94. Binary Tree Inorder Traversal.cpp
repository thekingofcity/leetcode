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
    vector<int> inorderTraversal(TreeNode* root) {
        while(root!=NULL||!s.empty()){
            while(root!=NULL){
                s.push(root);
                root=root->left;
            }
            root=s.top();s.pop();
            ret.push_back(root->val);
            root=root->right;
        }
        return ret;
    }
};
/*
[1,null,2,3]
[1,2,3]
[]
*/