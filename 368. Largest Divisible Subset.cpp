class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int l=nums.size(),m=0;
        if(l<=1) return nums;
        sort(nums.begin(),nums.end());
        vector<int> count(l, 1);
        vector<int> pre(l, -1);
        for(int i=0;i<l;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]%nums[j]==0){
                    if(count[i]<count[j]+1){
                        count[i]=count[j]+1;
                        pre[i]=j;
                        if(count[i]>count[m]){
                            m=i;
                        }
                    }
                }
            }
        }
        vector<int> ret;
        while(m!=-1){
            ret.push_back(nums[m]);
            m=pre[m];
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};