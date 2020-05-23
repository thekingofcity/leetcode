class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ret;
        for(int i=1;i<10;i++){
            dfs(ret, n, i);
        }
        return ret;
    }
    void dfs(vector<int>& ret, int n, int i){
        if(i>n) return;
        ret.push_back(i);
        for(int j=0;j<10;j++){
            if(i*10+j>n) return;
            dfs(ret, n, i*10+j);
        }
        return;
    }
};