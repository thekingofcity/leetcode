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

// 剑指offer 面试题59
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ret;
        q.push_back(0);
        if(k==1) ret.push_back(nums[0]);
        for(int i=1;i<nums.size();++i){
            if(nums[i]>=nums[q.front()]){
                while(q.size()&&nums[i]>=nums[q.front()])
                    q.pop_front();
                q.push_front(i);
            }else{
                while(q.size()&&nums[i]>=nums[q.back()])
                    q.pop_back();
                q.push_back(i);
            }
            while(q.size()&&i-q.front()>=k)
                q.pop_front();
            // for(auto x:q) cout<<x<<' '; cout<<endl;
            if(i>=k-1&&q.size())
                ret.push_back(nums[q.front()]);
        }
        return ret;
    }
};