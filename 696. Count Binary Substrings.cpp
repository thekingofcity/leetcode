// https://leetcode.com/problems/count-binary-substrings/solution/
class Solution {
public:
    int countBinarySubstrings(string s) {
        if(s.size()<2) return 0;
        vector<int> g;
        int sum=1;
        for(int i=1,l=s.size();i<l;++i){
            if(s[i]!=s[i-1]){
                g.push_back(sum);
                sum=1;
            }else ++sum;
        }
        if(sum) g.push_back(sum);
        // for(auto _:g) cout<<_<<' '; cout<<endl;
        
        if(g.size()<2) return 0;
        int ret=0;
        for(int i=1,l=g.size();i<l;++i)
            ret+=min(g[i],g[i-1]);
        return ret;
    }
};