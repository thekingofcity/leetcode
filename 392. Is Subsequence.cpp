class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0;
        while(i<=s.size()&&j<=t.size()){
            if(i==s.size()) return true;
            if(j==t.size()) return false;
            if(s[i]==t[j]) i++;
            j++;
        }
        return false;
    }
};
class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<set<int>> idx(128, set<int>());
        for(int i=0;i<t.size();i++) idx[t[i]].insert(i);
        
        int prev=-1;
        for(int i=0;i<s.size();i++){
            if(idx[s[i]].size()==0) return false;
            auto next=idx[s[i]].upper_bound(prev);
            if(next==idx[s[i]].end()) return false;
            prev=*next;
        }
        return true;
    }
};