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
        vector<TreeNode*> ppath(1, root);
        vector<TreeNode*> qpath(1, root);
        find(root, p, ppath);
        find(root, q, qpath);
        // for(auto x:ppath) cout<<x->val<<' '; cout<<endl;
        // for(auto x:qpath) cout<<x->val<<' '; cout<<endl;
        int i=0;
        for(;i<ppath.size()&&i<qpath.size();i++){
            if(ppath[i]!=qpath[i]) return ppath[i-1];
        }
        i--;
        if(ppath[i]==qpath[i]) return ppath[i];
        return root;
    }
    bool find(TreeNode* root, TreeNode* x, vector<TreeNode*> &path){
        if(!root) return false;
        if(root->val==x->val) return true;
        
        path.push_back(root->left);
        if(find(root->left, x, path)) return true;
        path.pop_back();
        
        path.push_back(root->right);
        if(find(root->right, x, path)) return true;
        path.pop_back();
        
        return false;
    }
};