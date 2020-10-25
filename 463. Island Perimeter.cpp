class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int total=0;
        for(int i=0;i<grid.size();++i){
            if(i==0&&grid[0][0]==1) total+=4;
            else if(i>0&&grid[i][0]==1) total+=grid[i-1][0]==1?2:4;
            for(int j=1;j<grid[0].size();++j){
                if(i==0){
                    if(grid[0][j]==1){
                        total+=grid[0][j-1]==1?2:4;
                        // cout<<total<<endl;
                    }
                }
                else if(grid[i][j]==1){
                    total+=grid[i-1][j]==1?-1:1;
                    total+=grid[i][j-1]==1?-1:1;
                    total+=2;
                    // cout<<total<<endl;
                }
            }
        }
        return total;
    }
};