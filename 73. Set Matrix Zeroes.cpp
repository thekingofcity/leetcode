class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size(),i=1,j=0;
        bool row0flag=false;
        // matrix[0][0] only represents col 0
        for(;j<n;++j){
            if(matrix[0][j]==0){
                 row0flag=true;
            }
        }
        for(;i<m;++i){
            for(j=0;j<n;++j){
                if(matrix[i][j]==0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        // Iterate over the array once again and using the first row and first column, update the elements.
        for (i = 1; i < m; i++) {
          for (j = 1; j < n; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
              matrix[i][j] = 0;
            }
          }
        }

        // See if the first column needs to be set to zero as well
        if (matrix[0][0] == 0) {
          for (i = 0; i < m; i++) {
            matrix[i][0] = 0;
          }
        }

        // See if the first row needs to be set to zero as well
        if (row0flag) {
          for (j = 0; j < n; j++) {
            matrix[0][j] = 0;
          }
        }

    }
};