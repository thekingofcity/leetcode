class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size()||!matrix[0].size()) return false;
        int end=matrix[0].size();
        int i=matrix.size()-1,j=0;
        while(true){
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]<target){
                j++;
                if(j>=end) return false;
            }
            else{
                i--;
                if(i<0) return false;
            }
        }
        return false;
    }
};