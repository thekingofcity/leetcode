class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<char> map(128, 0);
        vector<bool> used(128, false);
        for(int i=0;i<s.size();i++){
            if(map[s[i]]==0){
                if(used[t[i]])
                    return false;
                map[s[i]]=t[i];
                used[t[i]]=true;
            }
            else
                if(t[i]!=map[s[i]])
                    return false;
        }
        return true;
    }
};