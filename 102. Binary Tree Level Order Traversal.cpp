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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ret;
        if(root==NULL) return ret;
        vector<int> level;
        q.push(root);
        TreeNode* temp;
        int curLevelSize=1, nextLevelSize=0;
        
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
                ret.push_back(level);
                level.clear();
                curLevelSize=nextLevelSize;
                nextLevelSize=0;
            }
        }
        return ret;
    }
};
/*
[3,9,20,null,null,15,7]
[]
[3]
[3,9,20]
[1,2,3,4,5]
*/