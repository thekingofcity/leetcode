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

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        for(int i=0;i<k-1;++i)
            pq.pop();
        return pq.top();
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int index=-1, left=0, right=nums.size()-1;
        --k;
        while(true){
            index=partition(nums, left, right);
            // cout<<index<<' '<<left<<' '<<right<<endl;
            // for(auto num:nums) cout<<num<<' '; cout<<endl;
            if(k==index) return nums[index];
            else if(index<k) left=index+1;
            else right=index-1;
        }
        return -1;
    }
    
    int partition(vector<int>& nums, int left, int right){
        int l=left+1,r=right;
        int pivot=nums[left];
        while(l<=r){
            if(pivot>nums[l]&&pivot<nums[r])
                swap(nums[l++], nums[r--]);
            if(pivot<=nums[l]) ++l;
            if(pivot>=nums[r]) --r;
        }
        swap(nums[left], nums[r]);
        return r;
    }
    int partitionAsc(vector<int>& nums, int left, int right){
        if(left>=right) return left;
        int pivot=left;
        for(int i=pivot+1;i<=right;++i){
            if(nums[i]>=nums[pivot])
                swap(nums[i], nums[right--]);
            else
                ++pivot;
        }
        swap(nums[left], nums[pivot]);
        return pivot;
    }
};