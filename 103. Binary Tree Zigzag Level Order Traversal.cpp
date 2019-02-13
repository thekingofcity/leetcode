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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ret;
        if(root==NULL) return ret;
        vector<int> level;
        q.push(root);
        TreeNode* temp;
        int curLevelSize=1, nextLevelSize=0;
        bool inorder=true;
        
        while(q.size()){
            temp=q.front();
            q.pop();
            --curLevelSize;
            level.push_back(temp->val);
            
            // cout<<temp->val<<" "<<curLevelSize<<" "<<nextLevelSize<<endl;
            
            if(temp->left!=NULL){
                q.push(temp->left);
                ++nextLevelSize;
            }
            if(temp->right!=NULL){
                q.push(temp->right);
                ++nextLevelSize;
            }
            if(curLevelSize==0){
                if(!inorder) reverse(level.begin(), level.end());
                inorder=!inorder;
                ret.push_back(level);
                level.clear();
                curLevelSize=nextLevelSize;
                nextLevelSize=0;
            }
        }
        return ret;
    }
};