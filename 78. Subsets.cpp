class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> elem;
        int i=0,n=nums.size(),k=1;
        for(k=0;k<=n;++k){
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
        for(;i<n;++i){
            elem.push_back(nums[i]);
            combineCore(i+1, n, k, nums, elem, ret);
            elem.pop_back();
        }
    }
};
/*
[]
[1]
[1,2,3]
*/