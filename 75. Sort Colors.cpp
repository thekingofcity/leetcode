class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> temp(nums.size(), 0);
        sortColors(0, nums.size()-1, nums, temp);
    }
    void sortColors(int left, int right, vector<int>& nums, vector<int>& temp){
        if(left<right){
            int mid=left+(right-left)/2;
            sortColors(left, mid, nums, temp);
            sortColors(mid+1, right, nums, temp);
            merge(left, right, mid, nums, temp);
        }
    }
    void merge(int left, int right, int mid, vector<int>& nums, vector<int>& temp){
        int l=left,r=mid+1,t=0;
        while(l<=mid&&r<=right){
            if(nums[l]>nums[r]){
                temp[t++]=nums[r++];
            }else{
                temp[t++]=nums[l++];
            }
        }
        while(l<=mid) temp[t++]=nums[l++];
        while(r<=right) temp[t++]=nums[r++];
        t=0;
        while(left<=right) nums[left++]=temp[t++];
    }
};
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> colors(3,0);
        int i=0,j=0;
        for(;i<nums.size();++i) ++colors[nums[i]];
        // for(i=0;i<3;++i) cout<<colors[i]<<endl;
        i=0;
        for(j=0;colors[0]>0;++j){
            --colors[0];
            nums[j]=0;
        }
        for(;colors[1]>0;++j){
            --colors[1];
            nums[j]=1;
        }
        for(;colors[2]>0;++j){
            --colors[2];
            nums[j]=2;
        }
    }
};