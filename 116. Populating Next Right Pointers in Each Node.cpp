/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if(root==NULL) return root;
        vector<Node*> level;
        q.push(root);
        Node* temp;
        int curLevelSize=1, nextLevelSize=0;
        
        while(q.size()){
            temp=q.front();
            q.pop();
            --curLevelSize;
            level.push_back(temp);
            
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
                int i=0;
                for(;i<level.size()-1;++i){
                    level[i]->next=level[i+1];
                }
                level[i]->next=NULL;
                level.clear();
                curLevelSize=nextLevelSize;
                nextLevelSize=0;
            }
        }
        return root;
    }
};
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        Node *start = root, *cur = NULL;
        while (start->left) {
            cur = start;
            while (cur) {
                cur->left->next = cur->right;
                if (cur->next) cur->right->next = cur->next->left;
                cur = cur->next;
            }
            start = start->left;
        }
        return root;
    }
};
class Solution {
public:
    void connect(TreeLinkNode *root) 
    {
        if( root == nullptr )
        {
            return;
        }
        if( root-> left != nullptr )
        {
            root-> left-> next = root-> right;
            if( root-> next != nullptr )
            {
                root-> right-> next = root-> next-> left;
            }
        }
        connect( root-> left );
        connect( root-> right );
    }
};