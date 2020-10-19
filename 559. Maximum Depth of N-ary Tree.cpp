/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        return maxDepth(root, 0);
    }
    
    int maxDepth(Node* root, int cur){
        if(nullptr==root) return cur;
        int ret=0;
        for(auto child:root->children){
            ret=max(ret, maxDepth(child, cur+1));
        }
        return ret+1;
    }
};