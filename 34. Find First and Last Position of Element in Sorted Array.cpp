class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) {vector<int> ret={-1,-1};return ret;}
        int left=searchEqualorGreater(nums,target);
        if(nums[left]!=target) {vector<int> ret={-1,-1};return ret;}
        int left_=searchEqualorGreater(nums,target+1);
        if(nums[left_]>target) {
            vector<int> ret={left,left_-1};
            return ret;
        }else{
            vector<int> ret={left,left_};
            return ret;
        }
    }
    int searchEqualorGreater(vector<int>& nums, int target){
        int low=0,high=nums.size()-1,mid,l=nums.size();
        while(low<high){
            //mid is always biased towards left
            mid=(low+high)/2;
            if(nums[mid]>=target){
                //we want to move hi to the left
                high=mid;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};