class Solution {
public:
    int mySqrt(int x) {
        if(x<2) return x;
        int low=1,high=x/2,mid,temp;
        while(low<=high){
            mid=low+(high-low)/2;
            temp=x/mid;
            if(mid==temp){
                return mid;
            }
            if(mid<temp){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return high;
    }
};