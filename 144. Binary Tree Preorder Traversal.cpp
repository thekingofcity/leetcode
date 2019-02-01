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
    vector<int> preorderTraversal(TreeNode* root) {
        while(root!=NULL||!s.empty()){
            while(root!=NULL){
                s.push(root);
                ret.push_back(root->val);
                root=root->left;
            }
            root=s.top();s.pop();
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