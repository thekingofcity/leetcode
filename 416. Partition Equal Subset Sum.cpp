class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0,n=nums.size();
        for(auto num:nums) sum+=num;
        if(sum%2!=0) return false;
        int subSum=sum/2;
        vector<vector<bool>> dp(n+1, vector<bool>(subSum+1, false));
        dp[0][0]=true;
        for(int i=1;i<=n;++i){
            int curr=nums[i-1];
            for(int j=0;j<=subSum;++j){
                if(j<curr){
                    dp[i][j]=dp[i-1][j];
                }else{
                    dp[i][j]=dp[i-1][j]||dp[i-1][j-curr];
                }
            }
        }
        return dp[n][subSum];
    }
};