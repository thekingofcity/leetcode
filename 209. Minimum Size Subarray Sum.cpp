class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int ret=INT_MAX;
        int res=0;
        int left=0,right=0;
        for(;right<nums.size();){
            res+=nums[right++];
            while(res>=s){
                ret=min(ret, right-left);
                res-=nums[left++];
            }
        }
        return ret==INT_MAX?0:ret;
    }
};