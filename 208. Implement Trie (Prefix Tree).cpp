struct Node {
     char val;
     bool end;
     Node* children[26]={NULL};
     Node(char x, bool e) : val(x), end(e) {}
};
class Trie {
private:
    Node *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node('a', false);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *cur=root; int l=word.size();
        for(int i=0;i<l;i++){
            char x=word[i];
            if(!cur->children[x-'a'])
                cur->children[x-'a']=new Node(x, false);
            cur=cur->children[x-'a'];
            if(i==l-1) cur->end=true;
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *cur=root; int l=word.size();
        for(int i=0;i<l;i++){
            char x=word[i];
            if(!cur->children[x-'a']) return false;
            cur=cur->children[x-'a'];
            if(i==l-1&&cur->end) return true;
        }
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *cur=root; int l=prefix.size();
        for(int i=0;i<l;i++){
            char x=prefix[i];
            if(!cur->children[x-'a']) return false;
            cur=cur->children[x-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */