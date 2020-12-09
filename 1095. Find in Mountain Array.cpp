/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peakIndex=peakIndexInMountainArray(mountainArr);
        int peak=mountainArr.get(peakIndex);

        if(target==peak)
            return peakIndex;
        else if(target>peak||target<0)
            return -1;

        int leftSide=findInMountainArray(target, mountainArr, 0, peakIndex, true);
        int rightSide=findInMountainArray(target, mountainArr, peakIndex, mountainArr.length()-1, false);

        if(leftSide==-1&&rightSide==-1)
            return -1;
        else if(leftSide==-1)
            return rightSide;
        else if(rightSide==-1)
            return leftSide;
        return leftSide;
    }
    
    int findInMountainArray(int target, MountainArray &mountainArr, int l_, int r_, bool asc){
        int l=l_,r=r_,mid=0;
        while(l<=r){
            mid=l+(r-l)/2;
            // cout<<l<<r<<mid<<endl;
            int midVal=mountainArr.get(mid);
            if(midVal==target)
                return mid;

            if(asc){
                if(target<midVal)
                    r=mid-1;
                else
                    l=mid+1;
            }else{
                if(target>midVal)
                    r=mid-1;
                else
                    l=mid+1;
            }
        }
        return -1;
    }
    
    int peakIndexInMountainArray(MountainArray &mountainArr) {
        int l=0,r=mountainArr.length()-1,mid=0;
        while(l<r){
            mid=l+(r-l)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1))
                l=mid+1;
            else
                r=mid;
        }
        return l;
    }
};