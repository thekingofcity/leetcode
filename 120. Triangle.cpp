class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty()||triangle[0].empty()) return 0;
        if(triangle.size()==1) return triangle[0][0];
        int i=1,j=0,l=2,lmax=triangle[triangle.size()-1].size(),ret=0;
        vector<int> upper_res(lmax,0);
        vector<int> res(lmax,0);
        upper_res[0]=triangle[0][0];
        for(;i<lmax;++i){
            res[0]=triangle[i][0]+upper_res[0]; // first
            for(j=1;j<l-1;++j){
                res[j]=min(upper_res[j-1],upper_res[j])+triangle[i][j];
            }
            res[j]=triangle[i][l-1]+upper_res[l-2];
            for(j=0;j<l;++j) upper_res[j]=res[j];
            ++l;
        }
        ret=res[0];
        for(i=1;i<lmax;++i) ret=min(ret,res[i]);
        return ret;
    }
};
/*
[[2],[3,4],[6,5,7],[4,1,8,3]]
[]
[[5]]
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle[triangle.size()-1].size());
        dp[0]=triangle[0][0];
        for(int i=1;i<triangle.size();++i){
            int leftUp=dp[0];
            dp[0]=dp[0]+triangle[i][0];
            for(int j=1;j<i;++j){
                int temp=min(leftUp, dp[j])+triangle[i][j];
                leftUp=dp[j];
                dp[j]=temp;
            }
            dp[i]=leftUp+triangle[i][i];
        }
        int ret=INT_MAX;
        for(int j=0;j<dp.size();++j)
            ret=min(ret, dp[j]);
        return ret;
    }
};