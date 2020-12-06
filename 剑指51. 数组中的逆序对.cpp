// https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof/solution/shu-zu-zhong-de-ni-xu-dui-by-leetcode-solution/
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if(nums.size()<2) return 0;
        vector<int> temp(nums.size(), 0);
        return reversePairs(nums, 0, nums.size()-1, temp);
    }

    int reversePairs(vector<int>& nums, int l, int r, vector<int>& temp){
        if(l==r) return 0;

        int mid=l+(r-l)/2;
        int left_part = reversePairs(nums, l, mid, temp);
        int right_part = reversePairs(nums, mid+1, r, temp);

        int cross = merge(nums, l, mid, r, temp);
        return left_part+right_part+cross;
    }

    int merge(vector<int>& nums, int l, int mid, int r, vector<int>& temp){
        for(int i=l;i<=r;++i){
            temp[i]=nums[i];
        }
        
        int i=l,j=mid+1,k=l;
        int count=0;
        for(;k<=r;){
            if(i==mid+1){
                nums[k++]=temp[j++];
            }else if(j==r+1){
                nums[k++]=temp[i++];
            }else if(temp[i]<=temp[j]){
                nums[k++]=temp[i++];
            }else{
                nums[k++]=temp[j++];
                count+=mid-i+1;
            }
        }

        return count;
    }
};