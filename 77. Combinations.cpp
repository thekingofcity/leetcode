class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> elem;
        if(n<1||k<1){
            ret.push_back(elem);
            return ret;
        }
        int i=1;
        combineCore(i, n, k, elem, ret);
        return ret;
    }
    
    void combineCore(int i, int n, int k, vector<int> &elem, vector<vector<int>> &ret){
        if(elem.size()==k){
            ret.push_back(elem);
            return;
        }
        for(;i<=n;++i){
            elem.push_back(i);
            combineCore(i+1, n, k, elem, ret);
            elem.pop_back();
        }
    }
};