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

// O(n)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==0) return -1;
        if(nums.size()==1) return 0;
        if(nums.size()>=2&&nums[0]>nums[1]) return 0;
        for(int i=1;i<nums.size()-1;++i)
            if(nums[i]>nums[i-1]&&nums[i]>nums[i+1])
                return i;
        if(nums[nums.size()-2]<nums[nums.size()-1]) return nums.size()-1;
        return -1;
    }
};

// O(logn)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==0) return -1;
        int l=0,r=nums.size()-1,mid=0;
        while(l<r){
            mid=l+(r-l)/2;
            if(nums[mid]<nums[mid+1])
                l=mid+1;
            else
                r=mid;
            
        }
        return l;
    }
};