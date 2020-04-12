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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        
        if(!root) return ret;
        string curpath=to_string(root->val);
        if(!root->left&&!root->right){
            ret.push_back(curpath);
            return ret;
        }
        _binaryTreePaths(root->left, curpath, ret);
        _binaryTreePaths(root->right, curpath, ret);
        
        return ret;
    }
    void _binaryTreePaths(TreeNode* root, string curpath, vector<string> &ret) {
        if(!root) return;
        curpath+="->"+to_string(root->val);
        if(!root->left&&!root->right){
            ret.push_back(curpath);
            return;
        }
        _binaryTreePaths(root->left, curpath, ret);
        _binaryTreePaths(root->right, curpath, ret);
    }
};