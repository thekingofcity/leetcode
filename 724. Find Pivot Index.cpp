class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.empty()) return -1;
        int sum=0,n=nums.size()-1;
        for(auto num:nums) sum+=num;
        int l=0,r=sum-nums[0];
        for(int i=0;i<n;++i){
            if(l==r) return i;
            l+=nums[i];
            r-=nums[i+1];
        }
        if(l==r) return n;
        return -1;
    }
};
// [1,7,3,6,5,6]
// [1,2,3]
// []
// [0,1,-1]
// [1,-1,0]
// [-1,-1,-1,1,1,1]