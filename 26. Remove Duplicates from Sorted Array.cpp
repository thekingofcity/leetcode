class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len=nums.size();
        if(len==0) return 0;
        int i,a=0,b=1;
        for(i=1;i<len;i++){
            if(nums[a]==nums[b]){
            }else{
                a++;
                nums[a]=nums[b];
            }
            b++;
        }
        return a+1;
    }
};
