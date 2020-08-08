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
private:
    unsigned long width=0;
    vector<vector<unsigned long>> levels;
public:
    int widthOfBinaryTree(TreeNode* root) {
        helper(root, 0, 0);
        return (int)width;
    }
    
    void helper(TreeNode *root, unsigned long index, unsigned long level){
        if(!root) return;
        if(level==levels.size()){
            vector<unsigned long> temp{index, index};
            levels.push_back(temp);
        }
        if(index<levels[level][0])
            levels[level][0]=index;
        if(index>levels[level][1])
            levels[level][1]=index;
        width=max(width, levels[level][1]-levels[level][0]+1);
        // cout<<level<<' '<<levels[level][1]<<' '<<levels[level][0]<<' '<<width<<endl;
        
        helper(root->left, 2*index, level+1);
        helper(root->right, 2*index+1, level+1);
    }
};
// [1,3,2,5,3,null,9]
// [1,2,null,5,3]
// [1,3,2,5]
// [1,3,2,5,null,null,9,6,null,null,7]
// [1,1,1,1,1,1,1,null,null,null,1,null,null,null,null,2,2,2,2,2,2,2,null,2,null,null,2,null,2]
// [0,0,0,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null]