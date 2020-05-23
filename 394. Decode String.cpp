class Solution {
public:
    string decodeString(string s) {
        string res="";
        int i=0;
        for(;i<s.size();i++){
            if(isalpha(s[i])) res.push_back(s[i]);
            else{
                int times=s[i++]-'0';
                while(isdigit(s[i])) times=times*10+s[i++]-'0';
                i++;  // alpha next [
                int j=i;
                for(int b=1;j<s.size();j++){
                    if(s[j]=='[') b++;
                    if(s[j]==']') b--;
                    if(!b) break;
                }
                string s_=decodeString(s.substr(i, j-i));
                for(int t=0;t<times;t++) res+=s_;
                i=j;
            }
        }
        return res;
    }
};