class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> map(128,0);
        for(auto c:s) map[c]++;
        for(auto c:t) map[c]--;
        for(auto c:map) if(c!=0) return false;
        return true;
    }
};