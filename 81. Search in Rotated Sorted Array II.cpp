class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1,mid=0;
        while(low<=high){
            mid=low+(high-low)/2;
            if(nums[mid]==target) return true;
            if(nums[low]<nums[mid]){
                if(target>=nums[low]&&target<nums[mid]){
                    high=mid-1;
                }else{
                    low=mid+1;
                }
            }else if(nums[low]>nums[mid]){
                if(target>nums[mid]&&target<=nums[high]){
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }else{
                ++low;
            }
        }
        return false;
    }
};