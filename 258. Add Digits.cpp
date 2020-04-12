// https://leetcode.com/problems/add-digits/discuss/68580/Accepted-C%2B%2B-O(1)-time-O(1)-space-1-Line-Solution-with-Detail-Explanations
class Solution {
public:
    int addDigits(int num) {
        return 1 + (num - 1) % 9;
    }
};