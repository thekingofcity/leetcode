class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0||matrix[0].size()==0) return 0;

        int w=matrix[0].size(),h=matrix.size();

        if(w==1&&h==1) return matrix[0][0]-'0';

        int ret=0;

        vector<vector<int>> d(h, vector<int>(w,0));
        for(int i=0;i<w;i++)
            if(matrix[0][i]=='1'){
                d[0][i]=1;
                ret=1;
            }
        for(int i=0;i<h;i++)
            if(matrix[i][0]=='1'){
                d[i][0]=1;
                ret=1;
            }

        for(int i=1;i<h;i++){
            for(int j=1;j<w;j++){
                if(matrix[i][j]=='0') continue;
                if(d[i-1][j-1]==d[i-1][j]&&d[i-1][j-1]==d[i][j-1])
                    d[i][j]=d[i-1][j-1]+1;
                else if(d[i-1][j-1]==0||d[i-1][j]==0||d[i][j-1]==0)
                    d[i][j]=1;
                else d[i][j]=min(min(d[i-1][j-1],d[i-1][j]),d[i][j-1])+1;
                ret=max(ret,d[i][j]*d[i][j]);
            }
        }
        return ret;
    }
};
// [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","1","1","1"]]
// [["0","1","0","1","0"],["0","1","1","1","1"],["1","1","1","1","0"],["1","1","1","1","0"],["0","0","1","0","1"]]
// [["0","0"],["0","0"]]
// [["1","1"],["1","1"]]
// [["0"]]
// [["1"]]
// [[]]
// []
// [["0","1"]]
// [["0","0"]]
// [["0"],["1"]]
// [["0"],["0"]]
// [["0","1"],["1","0"]]
// [["0","1"],["1","1"]]
// [["1","1"],["1","1"]]
// [["0","0","0","1"],["1","1","0","1"],["1","1","1","1"],["0","1","1","1"],["0","1","1","1"]]
// [["1","1","1","0","0"],["1","1","1","0","0"],["1","1","1","1","1"],["0","1","1","1","1"],["0","1","1","1","1"],["0","1","1","1","1"]]
