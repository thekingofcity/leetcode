// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/discuss/94930/O(n)-solution-with-detailed-explanation.
// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/discuss/94917/Java-O(n)-Time-using-QuickSelect

// O(nlogn)
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int median=nums[nums.size()/2];
        int total=0;
        for(auto num:nums)
            total+=abs(num-median);
        return total;
    }
};

// O(n)
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        auto it = nums.begin() + nums.size()/2;
        nth_element(nums.begin(), it, nums.end());
        int median = *it;
        int total=0;
        for(auto num:nums)
            total+=abs(num-median);
        return total;
    }
};