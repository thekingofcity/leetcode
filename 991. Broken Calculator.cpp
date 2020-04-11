class Solution {
public:
    int brokenCalc(int X, int Y) {
        int cur=Y;
        int ops=0;
        while(cur>X){
            ops++;
            cur=cur%2?cur+1:cur/2;
        }
        return ops+X-cur;
    }
};