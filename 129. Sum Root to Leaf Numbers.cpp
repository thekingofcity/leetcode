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
    int sumNumbers(TreeNode* root) {
        vector<int> stack;
        int sum=0;
        sumNumbers(root, stack, sum);
        return sum;
    }
    
    
    void sumNumbers(TreeNode* root, vector<int>& stack, int& sum) {
        if(root==NULL){
            return;
        }else{
            stack.push_back(root->val);
            if(root->left==NULL&&root->right==NULL){
                int temp=0;
                for(auto it=stack.begin();it!=stack.end();++it){
                    temp=*it+temp*10;
                }
                sum+=temp;
            }else{
                if(root->left!=NULL) sumNumbers(root->left, stack, sum);
                if(root->right!=NULL) sumNumbers(root->right, stack, sum);
            }
            stack.pop_back();
        }
    }
};