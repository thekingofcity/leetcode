class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for(int i=0,l=s.size();i<l;++i){
            if(s[i]=='(') st.push(i);
            else if(s[i]==')'){
                if(st.empty()){
                    s[i]='*';
                    --i;
                }else{
                    st.pop();
                }
            }
        }
        
        while(st.size()){
            s[st.top()]='*';
            st.pop();
        }
        
        string ret="";
        for(const auto &c:s){
            if(c!='*')
                ret+=c;
        }
        return ret;
    }
};