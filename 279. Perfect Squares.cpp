class Solution {
public:
    int numSquares(int n) {
        static vector<int> dp={0,1};
        if(n>dp.size()-1){
            for(int i=dp.size();i<=n;i++){
                if((int)sqrt(i)*(int)sqrt(i)==i){dp.push_back(1);continue;}
                int m=INT_MAX;
                for(int j=1;j*j<=n;j++){
                    if(i-j*j>0) m=min(m, dp[i-j*j]+1);
                    // if(i==11&&i-s>0) cout<<dp[i-s]<<' '<<m<<' ';
                }
                dp.push_back(m);
            }
        }
        // cout<<endl; for(auto _:dp) cout<<_<<' '; cout<<endl;
        return dp[n];
    }
};