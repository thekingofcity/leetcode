class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty()||grid[0].empty()) return 0;
        int i=1,j=1,lrow=grid.size(),lcol=grid[0].size();
        vector<int> res(lcol,0);
        res[0]=grid[0][0];
        
        for(j=1;j<lcol;++j){
            res[j]=grid[0][j]+res[j-1];
        }
        for(;i<lrow;++i){
            res[0]+=grid[i][0];
            for(j=1;j<lcol;++j){
                res[j]=min(res[j],res[j-1])+grid[i][j];
            }
        }
        return res[lcol-1];
    }
};
/*
[[1,3,1],[1,5,1],[4,2,1]]
[]
[[1,2],[3,4]]
[[1,2,3,4]]
[[1],[2],[3],[4]]
*/