class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> ret;
		vector<int>::iterator it, it_;
		vector<int>::iterator _ = nums.begin(), __ = nums.end();
		for (it = _; it != __; it++) {
			for (it_ = it + 1; it_ != __; it_++) {
				if (*it + *it_ == target){
					ret.push_back(distance(_, it));
					ret.push_back(distance(_, it_));
					return ret;
				}
			}
		}
	}
};
//Runtime: 180 ms
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        vector<int> ret;
        for(int i=0;i<nums.size();++i)
            m[nums[i]]=i;
        for(int i=0;i<nums.size();++i){
            auto it=m.find(target-nums[i]);
            if(it!=m.end()&&it->second!=i){
                ret.push_back(i);
                ret.push_back(it->second);
                return ret;
            }
        }
        return ret;
    }
};