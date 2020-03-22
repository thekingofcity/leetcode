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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // get a path from root to p/q
        vector<TreeNode*> pathP, pathQ;
        findPath(root, p, pathP);
        findPath(root, q, pathQ);
        
        reverse(pathP.begin(), pathP.end());
        reverse(pathQ.begin(), pathQ.end());
        
        // find the most left common
        int i=1,l=min(pathP.size(),pathQ.size());
        for(;i<l;i++){
            if(pathP[i]!=pathQ[i]){
                return pathP[i-1];
            }
        }
        
        // we allow a node to be a descendant of itself
        i--;
        if(pathP[i]==pathQ[i]) return pathP[i];
        
        return root;
    }
    
    bool findPath(TreeNode* root, TreeNode* x, vector<TreeNode*> &path){
        if(root==x){
            path.push_back(x);
            return true;
        }
        
        if(root->left&&findPath(root->left, x, path)){
            path.push_back(root);
            return true;
        }
        if(root->right&&findPath(root->right, x, path)){
            path.push_back(root);
            return true;
        }
        return false;
    }
};

// or, from the discussion

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        return !left ? right : !right ? left : root;
    }
};