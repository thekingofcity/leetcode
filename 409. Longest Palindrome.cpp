class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> m;
        for(auto c:s) ++m[c];
        int max_odd=0,odd=0,even=0;
        auto max_odd_it=m.begin();
        for(auto it=m.begin();it!=m.end();++it)
            if(it->second&1){
                if(max_odd<it->second){
                    max_odd=it->second;
                    max_odd_it=it;
                }
            }
            else
                even+=it->second;
        m.erase(max_odd_it);
        for(auto it=m.begin();it!=m.end();++it)
            if(it->second&1&&it->second>1)
                odd+=it->second-1;
        return max_odd+odd+even;
    }
};