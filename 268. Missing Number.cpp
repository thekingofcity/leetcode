class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // Gauss' Formula
        long long expected=nums.size()*(nums.size()+1)/2;
        long long sum=0;
        for(auto num:nums) sum+=num;
        return expected-sum;
    }
};