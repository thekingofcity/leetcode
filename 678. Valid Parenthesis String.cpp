class Solution {
public:
    bool checkValidString(string s) {
        int lo=0,hi=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                lo++;hi++;
            }else if(s[i]==')'){
                lo--;hi--;
            }else{
                lo--;hi++;
            }
            if(hi<0) return false;
            
            // but when the lo<0, that means there are more ‘)’s than ‘(’s, and we need to stop early at that route, since it is invalid.
            lo=max(lo,0);
        }
        return lo==0;
    }
};