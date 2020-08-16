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

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1,mid=0;
        while(l<=r){
            mid=(l+r)/2;
            if(nums[mid]==target) return true;

            // search in linear time if l==mid==r
            if(nums[l]==nums[mid]&&nums[mid]==nums[r]){
                for(int i=l;i<=r;++i)
                    if(nums[i]==target)
                        return true;
                return false;
            }

            if(nums[l]<=nums[mid])
                if(nums[l]<=target&&target<=nums[mid])
                    r=mid-1;
                else
                    l=mid+1;
            else
                if(nums[mid]<=target&&target<=nums[r])
                    l=mid+1;
                else
                    r=mid-1;
        }
        return false;
    }
};