class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        bool log=false;
        // bool log=true;
        int l=nums.size(),i,j,k,temp;
        for(i=l-2,j=l-1;i>=0;i--,j--){
            if(nums[i]<nums[j]) break;
        }
        if(log) cout<<i<<' '<<nums[i]<<endl;
        if(i==-1){
            reverse(nums.begin(),nums.end());
        }else{
            for(k=l-1;k>i;k--){
                if(nums[k]>nums[i]) break;
            }
            if(log) cout<<k<<' '<<nums[k]<<endl;
            
            temp=nums[i];
            nums[i]=nums[k];
            nums[k]=temp;
            
            reverse(nums.begin()+i+1,nums.end());
        }
    }
};