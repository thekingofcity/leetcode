// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/discuss/27976/3-6-easy-lines-C%2B%2B-Java-Python-Ruby

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l=nums.size(),k=2;
        if(l<=k) return l;
        int slow=0;
        for(int fast=0;fast<l;fast++){
            if(slow<2||nums[fast]>nums[slow-k]){
                nums[slow++]=nums[fast];
            }
        }
        return slow;
    }
};