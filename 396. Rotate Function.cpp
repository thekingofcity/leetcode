// https://leetcode.com/problems/rotate-function/discuss/87853/Java-O(n)-solution-with-explanation
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        long allsum=0,F=0,ret=0;
        for(int i=0;i<A.size();i++) {
            F+=i*A[i];
            allsum+=A[i];
        }
        ret=F;
        for(int k=A.size()-1;k>0;k--){
            F=F+allsum-A.size()*A[k];
            ret=max(F,ret);
        }
        return (int)ret;
    }
};