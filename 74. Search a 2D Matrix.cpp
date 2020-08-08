class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size()||!matrix[0].size()) return false;
        int I=matrix.size(),J=matrix[0].size();
        int i=0,j=0;
        while(true){
            if(matrix[i][j]==target)
                return true;
            else if(j==0&&i+1<I&&matrix[i+1][j]<=target)
                ++i;
            else
                ++j;
            if(i>=I||j>=J)
                return false;
        }
        return false;
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int n = matrix.size();
        if(n==0) return false;
        int m = matrix[0].size();
        if(m==0) return false;
        int l = 0, r = m * n - 1;
        while (l != r){
            int mid = (l + r - 1) >> 1;
            if (matrix[mid / m][mid % m] < target)
                l = mid + 1;
            else 
                r = mid;
        }
        return matrix[r / m][r % m] == target;
    }
};