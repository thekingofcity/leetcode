// https://leetcode.com/problems/random-pick-with-weight/discuss/154044/Java-accumulated-freq-sum-and-binary-search
// https://leetcode.com/problems/random-pick-with-weight/discuss/671632/C%2B%2B-simple-and-easy-solution-with-explanation
class Solution {
private:
    vector<int> v;
public:
    Solution(vector<int>& w) {
        for(int i=1,l=w.size();i<l;++i)
            w[i]+=w[i-1];
        v=w;
    }
    
    int pickIndex() {
        int n=rand()%v[v.size()-1];
        auto it=upper_bound(v.begin(),v.end(),n);
        return it-v.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */