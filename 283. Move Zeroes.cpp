class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0,l=nums.size(),zero=0;
        
        // get the first zero and non-zero index
        while(zero<l&&nums[zero]!=0) zero++;
        while(i<l&&nums[i]==0) i++;
        
        while(i<l){
            if(i>zero){
                swap(nums,i,zero);
                // find the next zero and non-zero index
                do{i++;} while(i<l&&nums[i]==0);
                do{zero++;} while(zero<l&&nums[zero]!=0);
            }else
                // get the first non-zero after zero, otherwise no need to swap
                do{i++;} while(i<l&&nums[i]==0);
        }
    }
    void swap(vector<int>& nums, int a, int b){
        int temp=nums[a];
        nums[a]=nums[b];
        nums[b]=temp;
    }
};