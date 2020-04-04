class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ret=nums[0];
        int maxi=ret,mini=ret;
        for(int i=1;i<nums.size();i++){
            int maxi_tmp=max(max(nums[i], maxi*nums[i]), mini*nums[i]);
            mini=min(min(nums[i], maxi*nums[i]), mini*nums[i]);
            maxi=maxi_tmp;
            
            ret=max(ret, maxi);
        }
        return ret;
    }
};