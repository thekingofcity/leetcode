class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> dict;
        set<string>::iterator it;
        string temp;
        int i=0,j=0,l=wordDict.size();
        for(;i<l;++i) dict.insert(wordDict[i]);
        
        l=s.size();
        bool *res=new bool[l+1]();
        res[0]=1;
        
        for(i=0;i<l;++i){
            for(j=0;j<=i;++j){
                temp=s.substr(j,i-j+1);
                if(res[j]){
                    it=dict.find(temp);
                    if(it!=dict.end()){
                        res[i+1]=1;
                        break;
                    }
                }
            }
        }
        return res[s.size()];
    }
};
/*
"leetcode"
["leet","code"]
"applepenapple"
["apple", "pen"]
"catsandog"
["cats", "dog", "sand", "and", "cat"]
""
["a"]
"a"
[]
"a"
["b"]
*/