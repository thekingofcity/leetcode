class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int l=0,r=A.size()-1,mid=0;
        while(l<r){
            mid=l+(r-l)/2;
            if(A[mid]<A[mid+1])
                l=mid+1;
            else
                r=mid;
        }
        return l;
    }
};