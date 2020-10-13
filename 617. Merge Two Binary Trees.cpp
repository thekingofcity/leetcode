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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (nullptr == t1 && nullptr == t2)
            return nullptr;
        TreeNode* root = new TreeNode();
        if (nullptr != t1)
            root->val += t1->val;
        if (nullptr != t2)
            root->val += t2->val;
        root->left = mergeTrees(nullptr == t1 ? nullptr : t1->left, nullptr == t2 ? nullptr : t2->left);
        root->right = mergeTrees(nullptr == t1 ? nullptr : t1->right, nullptr == t2 ? nullptr : t2->right);
        return root;
    }
};