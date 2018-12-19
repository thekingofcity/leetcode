// should use bitwise operation for faster operation
// https://leetcode.com/problems/divide-two-integers/discuss/13407/Detailed-Explained-8ms-C%2B%2B-solution
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        if(divisor==1){return dividend;}
        if(divisor==-1){return -dividend;}
        int flag=((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        if(dividend<0) dividend=-dividend;
        if(divisor<0) divisor=-divisor;
        int i,remain=dividend;
        for(i=0;remain-divisor>=0;i++){
            remain-=divisor;
        }
        if(flag){
            return i;
        }else{
            return -i;
        }
    }
};