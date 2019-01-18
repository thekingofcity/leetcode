class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        if(n>=1){
            ans=myPowCore(x, n);
        }else if(n==0){
        }else{
            n=-n;
            ans=myPowCore(x, n);
            ans=1/ans;
        }
        return ans;
    }
    
    double myPowCore(double x, unsigned int n){
        if(n==0) return 1;
        if(n==1) return x;
        double ret=myPowCore(x,n>>1);
        ret*=ret;
        if(n&1==1){
            ret*=x;
        }
        return ret;
    }
};
/*
2.00000
10
2.10000
3
2.00000
-2
1
0
0
0
0.00001
2147483647
*/