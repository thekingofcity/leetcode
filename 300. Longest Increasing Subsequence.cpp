class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size(),i=1,j=0,ret=1,maxval=0;
        if(n==0) return 0;
        vector<int> res(n, 0);
        res[0]=1;
        for(;i<n;++i){
            maxval=1;
            for(j=0;j<i;++j){
                if(nums[i]>nums[j]){
                    maxval=max(maxval, res[j]+1);
                }
            }
            res[j]=maxval;
            ret=max(ret, maxval);
        }
        return ret;
    }
};
/*
[4,10,4,3,8,9]
[10,9,2,5,3,7,101,18]
[1,2,3,4]
[4,3,2,1]
[11,15,3,7,5,8,1]
*/