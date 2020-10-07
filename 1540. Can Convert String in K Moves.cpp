class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if(s.size()!=t.size()) return false;
        vector<vector<int>> m(26, vector<int>());
        for(int i=0,l=s.size();i<l;++i){
            int index=t[i]-s[i];
            if(index==0) continue;
            if(index<0) index+=26;
            m[index].push_back(m[index].size()*26+index);
            if(m[index].back()>k) return false;
        }
        return true;
    }
};