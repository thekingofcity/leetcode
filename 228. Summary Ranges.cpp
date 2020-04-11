class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size()==0) return vector<string>();
        if(nums.size()==1) return vector<string>(1,to_string(nums[0]));
        int l=0,r=1;
        vector<string> ret;
        for(;r<nums.size();r++){
            if(nums[r]!=nums[r-1]+1){
                string tmp;
                if(r-1!=l)
                    tmp=to_string(nums[l])+"->"+to_string(nums[r-1]);
                else
                    tmp=to_string(nums[l]);
                ret.push_back(tmp);
                l=r;
            }
            
        }
        if(r-1!=l)
            ret.push_back(to_string(nums[l])+"->"+to_string(nums[r-1]));
        else
            ret.push_back(to_string(nums[l]));
        return ret;
    }
};