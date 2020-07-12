class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int l=A[0].size();
        vector<vector<int>> ret(l, vector<int>(A.size()));
        for(int i=0;i<A.size();++i){
            for(int j=0;j<l;++j){
                ret[j][i]=A[i][j];
            }
        }
        return ret;
    }
};
