class Solution {
public:
    int integerBreak(int n) {
        if(n==2||n==3) return n-1;
        int ret=1;
        while(n>4){
            ret*=3;
            n-=3;
        }
        return ret*n;
    }
};