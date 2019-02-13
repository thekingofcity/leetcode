class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int l=amount+1,i=1,lc=coins.size(),j=0,minCount=0;
        if(lc==0) return -1;
        if(amount==0) return 0;
        vector<int> dp(amount+1, -1);
        dp[0]=0;
        for(;i<l;++i){
            minCount=INT_MAX;
            for(j=0;j<lc;++j){
                if(i-coins[j]>=0&&dp[i-coins[j]]!=-1){
                    minCount=min(minCount, dp[i-coins[j]]);
                }
            }
            dp[i]=minCount==INT_MAX?-1:minCount+1;
        }
        return dp[amount];
    }
};
/*
[1,2,5]
11
[2]
3
[2]
1
[186,419,83,408]
6249
*/