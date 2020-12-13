class Solution {
private:
    vector<int> origin, nums;
public:
    Solution(vector<int>& nums_) {
        origin=vector<int>(nums_.begin(), nums_.end());
        nums=vector<int>(nums_.begin(), nums_.end());
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        // nums=vector<int>(origin.begin(), origin.end());
        return origin;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        next_permutation(nums.begin(), nums.end());
        return nums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */