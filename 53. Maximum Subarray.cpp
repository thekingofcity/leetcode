class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i=0,l=nums.size(),maxSum=INT_MIN,curSum=0;
        for(;i<l;++i){
            if(curSum<0){
                curSum=nums[i];
            }else{
                curSum+=nums[i];
            }
            if(curSum>maxSum) maxSum=curSum;
        }
        return maxSum;
    }
};