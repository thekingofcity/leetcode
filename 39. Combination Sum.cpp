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