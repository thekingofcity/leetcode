class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ret=0,count=0;
        for(auto num:nums){
            if(count==0){
                ret=num;
                ++count;
            }
            else{
                if(num==ret) ++count;
                else --count;
            }
        }
        return ret;
    }
};