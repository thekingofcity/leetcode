class Solution {
public:
    string reverseWords(string s) {
        string ret;
        for(int i=s.size()-1;i>=0;--i){
            if(s[i]==' '){
                // if(i!=s.size()-1&&s[i+1]==' ') continue;
                int j=i+1;
                for(;j<s.size();++j){
                    if(s[j]==' ') break;
                    ret.push_back(s[j]);
                }
                if(j>i+1) ret.push_back(' ');
            }
        }
        if(s[0]!=' '){
            for(int j=0;j<s.size();++j){
                if(s[j]==' ') break;
                ret.push_back(s[j]);
            }
        }
        if(ret[ret.size()-1]==' ') ret.pop_back();
        return ret;
    }
};