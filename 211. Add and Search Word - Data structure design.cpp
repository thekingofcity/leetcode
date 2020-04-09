struct Node {
     char val;
     bool end;
     Node* children[26]={NULL};
     Node(char x, bool e) : val(x), end(e) {}
};
class WordDictionary {
private:
    Node *root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node('a', false);
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node *cur=root; int l=word.size();
        for(int i=0;i<l;i++){
            char x=word[i];
            if(!cur->children[x-'a'])
                cur->children[x-'a']=new Node(x, false);
            cur=cur->children[x-'a'];
            if(i==l-1) cur->end=true;
        }
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return _search(word, root);
    }
    
    bool _search(string word, Node *cur){
        if(word=="") return cur->end;

        int l=word.size();
        for(int i=0;i<l;i++){
            char x=word[i];
            if(x!='.'){
                if(!cur->children[x-'a']) return false;
                cur=cur->children[x-'a'];
                if(i==l-1&&cur->end) return true;
            }else{
                for(int j=0;j<26;j++){
                    if(cur->children[j])
                        if(_search(word.substr(i+1), cur->children[j]))
                            return true;
                }
                return false;
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */