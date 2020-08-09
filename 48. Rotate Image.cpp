// https://leetcode.com/problems/rotate-image/discuss/18872/A-common-method-to-rotate-the-image
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        for(int i=0;i<matrix.size();++i)
            for(int j=i+1;j<matrix.size();++j)
                swap(matrix[i][j], matrix[j][i]);
    }
};

// Can't get it done
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int l=matrix.size()>>1,m=matrix.size()-1;
        for(int i=0;i<=l;++i){
            for(int j=i;j<=m;++j){
                int temp=matrix[i][j];
                matrix[i][j]=matrix[m-j][i];
                matrix[m-j][i]=matrix[m-i][m-j];
                matrix[m-i][m-j]=matrix[j][m-i];
                matrix[j][m-i]=temp;
                print(matrix);
            }
        }
    }
    void print(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();++i){
            for(int j=0;j<matrix.size();++j){
                printf("%2d ", matrix[i][j]);
            }
            cout<<endl;
        }
        cout<<endl;
    }
};
// Should be something like this
// [~i] = [n-1-i]
class Solution:
    def rotate(self, A):
        n = len(A)
        for i in range(n/2):
            for j in range(n-n/2):
                A[i][j], A[~j][i], A[~i][~j], A[j][~i] = \
                         A[~j][i], A[~i][~j], A[j][~i], A[i][j]
// [[1,2,3],[4,5,6],[7,8,9]]
// [[1,2,3,4,5],[6,7,8,9,10],[11,12,13,14,15],[16,17,18,19,20],[21,22,23,24,25]]