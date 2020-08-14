/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
private:
    TreeNode* head=nullptr;
    TreeNode* pre=nullptr;
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(!pRootOfTree) return nullptr;
        helper(pRootOfTree);
        return head;
    }
    
    void helper(TreeNode* root){
        if(!root) return;
        helper(root->left);
        if(!head){
            head=root;
            pre=root;
        }else{
            pre->right=root;
            root->left=pre;
            pre=root;
        }
        helper(root->right);
    }
};