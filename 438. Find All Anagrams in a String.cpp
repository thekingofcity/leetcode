class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> m(128, 0);
        vector<int> ret;
        for(auto c:p) ++m[c];
        int l=0,r=0,len=s.size(),count=0;
        while(r<len){
            if(m[s[r++]]-->0) ++count;
            while(count==p.size()){
                if(r-l==p.size()) ret.push_back(l);
                if(m[s[l++]]++==0) --count;
            }
        }
        return ret;
    }
};