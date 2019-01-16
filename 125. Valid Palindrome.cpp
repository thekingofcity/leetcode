class Solution {
public:
    bool isPalindrome(string s) {
        string ret=getString(s);
        // cout<<ret<<endl;
        int i=0,j=ret.size()-1,l=ret.size()>>1;
        for(;i<l;++i){
            if(ret.at(i)==ret.at(j-i)){
                continue;
            }else{
                return false;
            }
        }
        return true;
    }
    
    string getString(string s){
        int i=0,j=0,l=s.size();
        char ch;
        string ret;
        for(;i<l;++i){
            ch=s.at(i);
            if(ch>='a'&&ch<='z'){
                ret.push_back(ch);
            }else if(ch>='A'&&ch<='Z'){
                ret.push_back(ch+32);
            }else if(ch>='0'&&ch<='9'){
                ret.push_back(ch);
            }
        }
        return ret;
    }
};
/*
"A man, a plan, a canal: Panama"
"race a car"
""
"1T1"
"0P"
*/