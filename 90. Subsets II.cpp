class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> elem;
        
        if(nums.size()==0){
            ret.push_back(elem);
            return ret;
        }
        
        sort(nums.begin(), nums.end());
        
        int i=0,n=nums.size(),k=0;
        for(;k<=n;++k){
            combineCore(i, n, k, nums, elem, ret);
        }
        return ret;
    }
    
    void combineCore(int i, int n, int k, vector<int>& nums,
                     vector<int> &elem, vector<vector<int>> &ret){
        if(elem.size()==k){
            ret.push_back(elem);
            return;
        }
        int index=i;
        for(;i<n;++i){
            if(i>index&&nums[i]==nums[i-1]) continue;
            elem.push_back(nums[i]);
            combineCore(i+1, n, k, nums, elem, ret);
            elem.pop_back();
        }
    }
    
};
/*
[1,2,2,3]
[1,2,2]
[]
[2,2,2,3]
[5,5,5,5,5]
*/