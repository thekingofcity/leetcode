class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> res(m,0);
        int i=0,j=1;
        for(;i<m;++i) res[i]=1;
        for(i=1;i<n;++i){
            res[0]=1;
            for(j=1;j<m;++j) res[j]=res[j-1]+res[j];
        }
        return res[m-1];
    }
};