class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1,mid;
        if(high==-1) return 0;
        while(low<high){
            mid=(low+high)/2;
            if(nums[mid]>=target){
                high=mid;
            }else{
                low=mid+1;
            }
        }
        if(nums[low]<target){return low+1;}
        else{return low;}
    }
};