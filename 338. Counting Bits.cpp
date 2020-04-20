// https://leetcode.com/problems/counting-bits/discuss/79539/Three-Line-Java-Solution
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num+1, 0);
        for(int i=1;i<=num;i++)
            ret[i]=ret[i/2]+(i&1);
        return ret;
    }
};