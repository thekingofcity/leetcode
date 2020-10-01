class Solution {
public:
    int countSubstrings(string s) {
        int ret=0;
        for(int i=0,l=s.size();i<l;++i){
            ret+=expandAroundCenter(s, i, i);
            ret+=expandAroundCenter(s, i, i+1);
        }
        return ret;
    }
    
    int expandAroundCenter(const string &s, int l, int r){
        int count=0;
        while(l>=0&&r<s.size()&&s[l--]==s[r++])
            ++count;
        return count;
    }
};