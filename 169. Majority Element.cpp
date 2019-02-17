class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ret=nums[0], count=1;;
        for(int i=1;i<nums.size();++i){
            if(count==0){
                ret=nums[i];
                ++count;
            }else if(nums[i]==ret){
                ++count;
            }else{
                --count;
            }
        }
        return ret;
    }
};