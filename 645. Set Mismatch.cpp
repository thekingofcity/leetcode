// time:O(n) space:O(n)
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> m(nums.size()+1, 0);
        for(auto num:nums)
            ++m[num];
        
        int missing=0,duplicate=0;
        for(int i=1;i<m.size();++i)
            if(m[i]==0)
                missing=i;
            else if(m[i]==2)
                duplicate=i;
        
        vector<int> ret;
        ret.push_back(duplicate);
        ret.push_back(missing);
        return ret;
    }
};

// time:O(n) space:O(1)
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int duplicate=-1,missing=-1;
        
        // revert each one, if <0 then duplicate
        for(auto num:nums)
            if(nums[abs(num)-1]<0)
                duplicate=abs(num);
            else
                nums[abs(num)-1]*=-1;

        // find the only >0 one
        for(int i=0;i<nums.size();++i)
            if(nums[i]>0)
                missing=i+1;
        
        vector<int> ret;
        ret.push_back(duplicate);
        ret.push_back(missing);
        return ret;
    }
};