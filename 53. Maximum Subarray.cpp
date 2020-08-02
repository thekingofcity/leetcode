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

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return INT_MIN;
        int m=nums[0],globalMax=nums[0];
        for(int i=1;i<nums.size();++i){
            if(m<0){
                m=nums[i];
                globalMax=max(globalMax, m);
            }else{
                m+=nums[i];
                globalMax=max(globalMax, m);
            }
        }
        return globalMax;
    }
};