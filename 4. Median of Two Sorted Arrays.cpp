// https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2588/O(lg(m+n))-c++-solution-using-kth-smallest-number/3215
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int k=(nums1.size()+nums2.size())>>1;
        int num1=findKth(nums1, 0, nums1.size(), nums2, 0, nums2.size(), k + 1);
        if ((nums1.size()+nums2.size())%2==0){
            int num2 = findKth(nums1, 0, nums1.size(), nums2, 0, nums2.size(), k);
            return (num1+num2)/2.0;
        }
        else return num1;
    }
    
    int findKth(vector<int> &A, int startA, int endA, vector<int> &B, int startB, int endB, int k) {
        int m = endA - startA, n = endB - startB;
        if (m > n) return findKth(B, startB, endB, A, startA, endA, k);
        if (m == 0) return B[startB + k - 1];
        if (k == 1) return min(A[startA], B[startB]);

        int i = min(k / 2, m), j = k - i;
        if (A[startA + i - 1] < B[startB + j - 1])
            return findKth(A, startA + i, endA, B, startB, endB, k - i);
        else if (A[startA + i - 1] > B[startB + j - 1])
            return findKth(A, startA, endA, B, startB + j, endB, k - j);
        else
            return A[startA + i - 1];
    }
};