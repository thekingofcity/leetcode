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
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root==NULL) return 0;
        if (!root->left) return sumOfLeftLeaves(root->right);
        int ret=0;
        if (root->left) {
            if (!root->left->left&&!root->left->right) ret+=root->left->val;
            else ret+=sumOfLeftLeaves(root->left);
        }
        ret+=sumOfLeftLeaves(root->right);
        return ret;
    }
};

class Solution {
private:
    int sum=0;
public:
    int sumOfLeftLeaves(TreeNode* root) {
        sumOfLeftLeaves(root, false);
        return sum;
    }
    void sumOfLeftLeaves(TreeNode* root, bool left) {
        if(nullptr==root) return;
        if(true==left&&nullptr==root->left&&nullptr==root->right){
            sum+=root->val;
            return;
        }
        sumOfLeftLeaves(root->left, true);
        sumOfLeftLeaves(root->right, false);
    }
};