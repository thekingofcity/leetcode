class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> m,n;
        for(auto c:chars) ++m[c];
        int ret=0;
        for(auto &word:words){
            n=m;
            bool flag=true;
            for(auto c:word){
                if(--n[c]<0){
                    flag=false;
                    break;
                }
            }
            if(flag){
                ret+=word.size();
            }
        }
        return ret;
    }
};