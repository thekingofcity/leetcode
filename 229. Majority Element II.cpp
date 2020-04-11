// https://leetcode.com/problems/majority-element-ii/discuss/63520/Boyer-Moore-Majority-Vote-algorithm-and-my-elaboration
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cx=0,cy=0,x=0,y=1;
        for(auto i:nums){
            if(i==x) cx++;
            else if(i==y) cy++;
            else if(cx==0) {x=i;cx++;}
            else if(cy==0) {y=i;cy++;}
            else {cx--;cy--;}
        }
        
        vector<int> ret;
        
        cx=0;
        for(auto i:nums)
            if(x==i) cx++;
        if(cx>nums.size()/3) ret.push_back(x);
        
        cy=0;
        for(auto i:nums)
            if(y==i) cy++;
        if(cy>nums.size()/3) ret.push_back(y);
        
        return ret;
    }
};