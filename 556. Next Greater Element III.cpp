// next_permutation
// https://leetcode.com/problems/next-greater-element-iii/
class Solution {
public:
    int nextGreaterElement(int n) {
        auto s=to_string(n);
        next_permutation(s.begin(), s.end());
        auto res=stoll(s);
        return (res>INT_MAX||res<=n)?-1:res;
    }
};