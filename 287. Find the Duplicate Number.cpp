class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast=0, slow=0;
        while(1){
            fast=nums[nums[fast]];
            slow=nums[slow];
            if(fast==slow) break;
        }
        int p1=slow, p2=0;
        while(p1!=p2){
            p1=nums[p1];
            p2=nums[p2];
        }
        return p1;
    }
};