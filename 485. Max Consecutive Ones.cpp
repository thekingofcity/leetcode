class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cur=0,m=0;
        for(const int num:nums){
            if(num==1)
                m=max(m,++cur);
            else
                cur=0;
        }
        return m;
    }
};