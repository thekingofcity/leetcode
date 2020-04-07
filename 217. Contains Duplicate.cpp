class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size()<=1) return false;
        sort(nums.begin(), nums.end());
        for(int i=1,last=nums[0];i<nums.size();i++){
            if(nums[i]==last) return true;
            last=nums[i];
        }
        return false;
    }
};