class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int x1=0,x2=matrix.size();
        if(x2==0) return ret;
        int y1=0,y2=matrix[0].size();
        if(y2==0) return ret;
        int i=0,j=0,count=x2*y2;
        for(;;){
            for(j=y1;j<y2;++j){
                ret.push_back(matrix[i][j]);
            }
            --j;
            ++x1;
            if(x1>x2||ret.size()==count) break;
            
            for(i=x1;i<x2;++i){
                ret.push_back(matrix[i][j]);
            }
            --i;
            --y2;
            if(y1>y2||ret.size()==count) break;
            
            for(j=y2-1;j>=y1;--j){
                ret.push_back(matrix[i][j]);
            }
            ++j;
            --x2;
            if(x1>x2||ret.size()==count) break;
            
            // i>x1 because the x1 row has been accessed
            for(i=x2-1;i>=x1;--i){
                ret.push_back(matrix[i][j]);
            }
            ++i;
            ++y1;
            if(y1>y2||ret.size()==count) break;
            
            // cout<<x1<<x2<<y1<<y2<<endl;
        }
        return ret;
    }
};
/*
[[1,2,3],[4,5,6],[7,8,9]]
[[1, 2, 3, 4,5],[6,7,8,9,10],[11,12,13,14,15]]
[[1,2,3],[4,5,6],[7,8,9],[10,11,12],[13,14,15]]
[[1,2,3,4,5]]
[[1],[2],[3],[4],[5]]
[]
[[],[],[]]
*/