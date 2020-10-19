// https://leetcode.com/problems/subarray-sum-equals-k/solution/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int l=nums.size(),count=0;
        for(int i=0;i<l;++i){
            int sum=0;
            for(int j=i;j<l;++j){
                sum+=nums[j];
                if(sum==k)
                    ++count;
            }
        }
        return count;
    }
};

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int l=nums.size(),count=0,sum=0;
        unordered_map<int, int> m;
        m[0]=1;
        for(int i=0;i<l;++i){
            sum+=nums[i];
            auto it=m.find(sum-k);
            if(it!=m.end())
                count+=it->second;
            it=m.find(sum);
            if(it!=m.end())
                m[sum]=it->second+1;
            else
                m[sum]=1;
        }
        return count;
    }
};
