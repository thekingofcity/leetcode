class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> record;
        vector<vector<int>> result;
        if(candidates.size()<1){
            result.push_back(record);
            return result;
        }
        combinationSum(candidates, target, 0, record, result);
        return result;
    }
    
    void combinationSum(vector<int>& candidates, int target, int index,
                        vector<int>& record, vector<vector<int>>& result){
        if(target<0) return;
        if(target==0){
            result.push_back(record);
            return;
        }
        int i,l=candidates.size();
        for(i=index;i<l;i++){
            record.push_back(candidates[i]);
            combinationSum(candidates, target-candidates[i], i, record, result);
            record.pop_back();
        }
    }
};
// this runs for 16ms and after some optimization we can reach 12ms
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> record;
        vector<vector<int>> result;
        if(candidates.size()<1){
            result.push_back(record);
            return result;
        }
        sort(candidates.begin(),candidates.end());
        combinationSum(candidates, target, 0, record, result);
        return result;
    }
    
    bool combinationSum(vector<int>& candidates, int target, int index,
                        vector<int>& record, vector<vector<int>>& result){
        if(target<0) return false;
        if(target==0){
            result.push_back(record);
            return false;
        }
        int i,l=candidates.size();
        bool flag=false;
        for(i=index;i<l;i++){
            record.push_back(candidates[i]);
            if(!combinationSum(candidates, target-candidates[i], i, record, result)) flag=true;
            record.pop_back();
            if(flag) break;
        }
        return true;
    }
};

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ret;
        vector<int> s;
        
        dfs(s, candidates, 0, ret, target);
        return ret;
    }
    
    void dfs(vector<int> &s, vector<int> &candidates, int i, vector<vector<int>> &ret, int target){
        int sum=0;
        for(auto n:s) sum+=n;
        // for(auto n:s) cout<<n<<' '; cout<<endl;
        if(sum>target) return;
        if(sum==target){
            ret.push_back(s);
            return;
        }
        
        for(int j=i;j<candidates.size();j++){
            if(sum+candidates[j]>target) break;
            s.push_back(candidates[j]);
            dfs(s, candidates, j, ret, target);
            s.pop_back();
        }
    }
};

class Solution {
private:
    vector<vector<int>> ret;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        helper(candidates, target, 0, path);
        return ret;
    }
    
    void helper(vector<int>& candidates, int target, int i, vector<int> &path){\
        if(0==target){
            ret.push_back(path);
        }else if(candidates[i]>target){
        }else{
            for(int j=i;j<candidates.size();++j){
                path.push_back(candidates[j]);
                helper(candidates, target-candidates[j], j, path);
                path.pop_back();
            }
        }
    }
};