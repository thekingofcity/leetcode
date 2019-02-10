class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size=nums.size(),i=0,max=0;
        if(size==0) return true;
        for(;i<size;++i){
            if(i>max) return false;
            if(i+nums[i]>max) max=i+nums[i];
        }
        if(max>=size-1) return true;
        return false;
    }
};