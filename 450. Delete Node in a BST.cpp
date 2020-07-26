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
    TreeNode* parent;
    TreeNode* cur;
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        find(root, key);
        if(!cur) return root;  // no node in bst
        
        if(parent){
            bool left=cur==parent->left?1:0;
            if(!cur->left&&!cur->right)
                // key has no children
                if(left) parent->left=NULL;
                else parent->right=NULL;
            else if(!cur->left)
                // key has only right children
                if(left) parent->left=cur->right;
                else parent->right=cur->right;
            else if(!cur->right)
                // key has only left children
                if(left) parent->left=cur->left;
                else parent->right=cur->left;
            else{
                TreeNode* leftMax=cur->left;
                while(leftMax->right)
                    leftMax=leftMax->right;
                leftMax->right=cur->right;
                if(left) parent->left=cur->left;
                else parent->right=cur->left;
            }
            return root;
        }else{
            // del root
            if(!cur->left&&!cur->right) return NULL;
            
            if(!cur->left) return cur->right;
            else if(!cur->right) return cur->left;
            
            TreeNode* leftMax=cur->left;
            while(leftMax->right)
                leftMax=leftMax->right;
            leftMax->right=cur->right;
            return cur->left;
        }
    }
    
    bool find(TreeNode* root, int key){
        if(!root) return false;
        if(root->val==key){
            cur=root;
            return true;
        }
        
        if(root->val>key){
            if(find(root->left, key)){
                parent=root;
                return false;
            }
        }else{
            if(find(root->right, key)){
                parent=root;
                return false;
            }
        }
        return false;
    }
};
// [5,3,6,2,4,null,7]
// 3
// [5,3,6,2,4,null,7]
// 4
// [5,3,7,2,4,6,8]
// 3
// [5,3,7,2,4,6,8]
// 6
// [5,3,7,2,4,6,8]
// 5
// [5,3,7,2,4]
// 5

// https://www.cnblogs.com/grandyang/p/6228252.html
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        TreeNode *cur = root, *pre = nullptr;
        while (cur) {
            if (cur->val == key) break;
            pre = cur;
            if (cur->val > key) cur = cur->left;
            else cur = cur->right;
        }
        if (!pre) return del(cur);
        if (pre->left && pre->left->val == key) pre->left = del(cur);
        else pre->right = del(cur);
        return root;
    }
    
    TreeNode* del(TreeNode* node) {
        if (!node) return nullptr;
        if (!node->right) return node->left;
        TreeNode *t = node->right;
        while (t->left) t = t->left;
        t->left = node->left;
        return node->right;
    }
};