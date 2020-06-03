// https://leetcode.com/problems/queue-reconstruction-by-height/discuss/89345/Easy-concept-with-PythonC%2B%2BJava-Solution
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        if (people.size()==0) return vector<vector<int>>();
        
        map<int,set<int>> m;
        for(auto p:people){
            if(m.find(p[0])==m.end()) m.insert({p[0],{p[1]}});
            else m.find(p[0])->second.insert(p[1]);
        }
        
        vector<vector<int>> ret;
        for(auto it=m.rbegin();it!=m.rend();++it){
            auto h=it->first;
            for(auto k:it->second){
                vector<int> res={h,k};
                if(k>ret.size()) ret.push_back(res);
                else ret.insert(ret.begin()+k,res);
            }
        }
        return ret;
    }
};