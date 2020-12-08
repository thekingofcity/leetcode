class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if(nums.empty()) return 0;
        if(S>1000||S<-1000) return 0;
        vector<vector<int>> dp(nums.size(), vector<int>(2001, 0));
        dp[0][nums[0]+1000]=1;
        dp[0][-nums[0]+1000]+=1;
        for(size_t i=1;i<nums.size();++i){
            for(int j=-1000;j<1001;++j){
                if(dp[i-1][j+1000]>0){
                    dp[i][j-nums[i]+1000]+=dp[i-1][j+1000];
                    dp[i][j+nums[i]+1000]+=dp[i-1][j+1000];
                }
            }
        }
        return dp[nums.size()-1][S+1000];
    }
};