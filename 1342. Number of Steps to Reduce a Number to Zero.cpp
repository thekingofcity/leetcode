class Solution {
public:
    int numberOfSteps (int num) {
        int ret=0;
        while(num!=0){
            if(num%2==1)
                num--;
            else
                num/=2;
            ret++;
        }
        return ret;
    }
    int numberOfSteps (int num) {
        if(!num) return 0;
        int ret=0;
        while(num){
            ret+=num&1?2:1;
            num>>=1;
        }
        return ret-1;
    }
};