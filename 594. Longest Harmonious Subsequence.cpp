// https://leetcode.com/problems/longest-harmonious-subsequence/solution/
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto num:nums) ++m[num];
        int ret=0;
        for(auto num:nums){
            auto it=m.find(num);
            auto it1=m.find(num+1);
            if(it1!=m.end()) ret=max(ret, it->second+it1->second);
            // else ret=max(ret, it->second);
        }
        return ret;
    }
};