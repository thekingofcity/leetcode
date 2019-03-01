class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1) return 0;
        if(nums[0]>nums[1]) return 0;
        int i=1,j=nums.size()-1;
        for(int i=1;i<j;++i){
            if(nums[i-1]<nums[i]&&nums[i]>nums[i+1]) return i;
        }
        return j;
    }
};
/*
[1,2,3,1]
[1,2,1,3,5,6,4]
[1]
[1,2]
[2,1]
[1,2,3]
*/