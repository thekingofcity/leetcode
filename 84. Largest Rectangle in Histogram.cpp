// time:O(n^2) space:O(n) TLE
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int h=heights.size();
        int ret=0;
        vector<int> dp(h, 0);
        for(int i=0;i<h;++i){
            int j=i;
            dp[j]=heights[j];
            ret=max(ret, heights[j]);
            for(++j;j<h;++j){
                dp[j]=min(dp[j-1], heights[j]);
                ret=max(ret, (j-i+1)*dp[j]);
            }
        }
        return ret;
    }
};

// time:O(n) space:O(n)
// https://leetcode.com/problems/largest-rectangle-in-histogram/discuss/28902/5ms-O(n)-Java-solution-explained-(beats-96)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int h=heights.size();
        if(h==0) return 0;
        
        vector<int> lessFromLeft(h, 0);
        vector<int> lessFromRight(h, 0);
        lessFromLeft[0]=-1;
        lessFromRight[h-1]=h;
        
        for(int i=0;i<h;++i){
            int p=i-1;
            while(p>=0&&heights[p]>=heights[i])
                p=lessFromLeft[p];
            lessFromLeft[i]=p;
        }
        
        for(int i=h-2;i>=0;--i){
            int p=i+1;
            while(p<h&&heights[p]>=heights[i])
                p=lessFromRight[p];
            lessFromRight[i]=p;
        }
        
        int ret=0;
        for(int i=0;i<h;++i){
            ret=max((lessFromRight[i]-lessFromLeft[i]-1)*heights[i], ret);
        }
        return ret;
    }
};