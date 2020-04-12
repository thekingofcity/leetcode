// https://leetcode.com/problems/sliding-window-maximum/discuss/65884/Java-O(n)-solution-using-deque-with-explanation
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        deque<int> q;
        for(int i=0;i<nums.size();i++){
            if(q.size()&&q.front()<i-k+1) q.pop_front();
            while(q.size()&&nums[q.back()]<=nums[i])
                q.pop_back();
            q.push_back(i);
            if(i>=k-1) ret.push_back(nums[q.front()]);
        }
        return ret;
    }
};