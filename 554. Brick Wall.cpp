class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> m;
        for(auto row:wall){
            for(int cut=0,i=0,l=row.size();i<l-1;++i){
                cut+=row[i];
                ++m[cut];
            }
        }
        int ret=0;
        for(auto it=m.begin();it!=m.end();++it){
            // cout<<it->first<<it->second<<endl;
            ret=max(ret, it->second);
        }
        return wall.size()-ret;
    }
};