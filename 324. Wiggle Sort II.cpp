// sort and pick the last one from left and the last one from the right part
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int l=nums.size();
        if(l<2) return;
        auto tmp=nums;
        sort(tmp.begin(), tmp.end());
        int i=0,big=l-1,small=(l+1)/2-1;
        for(;i<l;i++){
            if(i%2==0)
                nums[i]=tmp[small--];
            else
                nums[i]=tmp[big--];
        }
    }
};