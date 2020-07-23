class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> record;
        vector<vector<int>> result;
        if(candidates.size()<1){
            result.push_back(record);
            return result;
        }
        combinationSum2(candidates, target, 0, record, result);
        return result;
    }
    
    void combinationSum2(vector<int>& candidates, int target, int index,
                        vector<int>& record, vector<vector<int>>& result){
        if(target<0) return;
        if(target==0){
            result.push_back(record);
            return;
        }
        for(int i=index;i<candidates.size();i++){
            if(i>index&&candidates[i]==candidates[i-1]) continue;
            record.push_back(candidates[i]);
            combinationSum2(candidates, target-candidates[i], i+1, record, result);
            record.pop_back();
        }
    }
};