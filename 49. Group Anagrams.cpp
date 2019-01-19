class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mymap;
        unordered_map<string, vector<string>>::iterator it;
        vector<vector<string>> ret;
        string s;
        for(int i=0;i<strs.size();++i){
            s=strs[i];
            sort(s.begin(), s.end());
            it=mymap.find(s);
            if(it==mymap.end()){
                vector<string> newvec{strs[i]};
                mymap.insert({s, newvec});
            }else{
                it->second.push_back(strs[i]);
            }
        }
        for(it=mymap.begin();it!=mymap.end();++it){
            ret.push_back(it->second);
        }
        return ret;
    }
};