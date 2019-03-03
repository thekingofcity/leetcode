class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()-k];
    }
};
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int cur=0,left=0,right=nums.size()-1;
        k=nums.size()-k;
        while (left<right){
            cur=partition(nums, left, right);
            if(cur==k){
                return nums[cur];
            }else if(cur>k){
                right=cur-1;
            }else{
                left=cur+1;
            }
        }
        return nums[right];
    }
    int partition(vector<int>& nums, int left, int right){
        int pivotIndex=left, pivot=nums[left];
        while(left<right){
            while(left<right&&nums[right]>=pivot) --right;
            while(left<right&&nums[left]<=pivot) ++left;
            swap(nums, left, right);
        }
        swap(nums, pivotIndex, left);
        return left;
    }
    void swap(vector<int>& nums, int a, int b){
        int temp=nums[a];
        nums[a]=nums[b];
        nums[b]=temp;
    }
};