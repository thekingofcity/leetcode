// https://www.cnblogs.com/yaoyudadudu/p/11724056.html
// https://www.youtube.com/watch?v=thLQYBlz2DM
class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> conns(n, vector<int>());
        for(const auto &conn:connections) {
            conns[conn[0]].push_back(conn[1]);
            conns[conn[1]].push_back(conn[0]);
        }

        int time = 0;
        vector<vector<int>> ret;
        vector<int> disc(n, -1), low(n, -1);
        dfs(0, 0, conns, time, ret, disc, low);
        return ret;
    }
    
    void dfs(int cur, int parent, vector<vector<int>>& conns, int &time, vector<vector<int>>& ret,
            vector<int>& disc, vector<int>& low) {
        if (disc[cur] == -1) 
            low[cur] = disc[cur] = time++;
        
        for(const auto edge:conns[cur]) {
            if (edge == parent) continue;
            
            if (disc[edge] == -1) {
                dfs(edge, cur, conns, time, ret, disc, low);
                low[cur] = min(low[cur], low[edge]);
                if (disc[cur] < low[edge])
                    ret.push_back({cur, edge});
            } else {
                low[cur] = min(low[cur], disc[edge]);
            }
        }
    }
};