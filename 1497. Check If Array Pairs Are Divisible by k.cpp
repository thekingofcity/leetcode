// https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/discuss/709212/Short-C%2B%2B-Solution-explained-with-comments
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> m;
        for(auto x:arr) ++m[(x%k + k)%k];
        for(auto x:arr){
            int reminder=(x%k + k)%k;
            if(reminder==0){
                if(m[x]&1)
                    return false;
            }else{
                if(m[reminder]!=m[k-reminder])
                    return false;
            }
        }
        return true;
    }
};