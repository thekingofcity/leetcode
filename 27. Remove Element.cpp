class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int a=-1,b,len=nums.size();
        for(b=0;b<len;b++){
            if(nums[b]!=val){
                a++;
                nums[a]=nums[b];
            }else{
                
            }
        }
        return a+1;
    }
};