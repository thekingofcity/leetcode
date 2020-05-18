class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int num:nums) m[num]--;
        
        priority_queue<pair<int,int>> pq;
        for(auto it=m.begin();it!=m.end();it++){
            pq.push({it->second, it->first});
            if(pq.size()>k) pq.pop();
        }
        
        vector<int> ret;
        while(pq.size()){
            ret.push_back(pq.top().second);
            pq.pop();
        }
        return ret;
    }
};