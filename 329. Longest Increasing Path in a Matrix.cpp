// simple dfs
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int res=0;
        vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));
        for(int i=0;i<matrix.size();++i){
            for(int j=0;j<matrix[0].size();++j){
                res=max(res, longestIncreasingPath(matrix, visited, i, j)+1);
            }
        }
        return res;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int x, int y) {
        int res=0,tmp=0;
        if(x-1>=0&&visited[x-1][y]==false&&matrix[x][y]<matrix[x-1][y]){
            visited[x-1][y]=true;
            tmp=max(tmp, longestIncreasingPath(matrix, visited, x-1, y)+1);
            visited[x-1][y]=false;
        }
        if(x+1<matrix.size()&&visited[x+1][y]==false&&matrix[x][y]<matrix[x+1][y]){
            visited[x+1][y]=true;
            tmp=max(tmp, longestIncreasingPath(matrix, visited, x+1, y)+1);
            visited[x+1][y]=false;
        }
        if(y-1>=0&&visited[x][y-1]==false&&matrix[x][y]<matrix[x][y-1]){
            visited[x][y-1]=true;
            tmp=max(tmp, longestIncreasingPath(matrix, visited, x, y-1)+1);
            visited[x][y-1]=false;
        }
        if(y+1<matrix[0].size()&&visited[x][y+1]==false&&matrix[x][y]<matrix[x][y+1]){
            visited[x][y+1]=true;
            tmp=max(tmp, longestIncreasingPath(matrix, visited, x, y+1)+1);
            visited[x][y+1]=false;
        }
        return tmp;
    }
};

// dfs with memo
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int res=0;
        if(matrix.empty()||matrix[0].empty()) return res;
        vector<vector<int>> memo(matrix.size(), vector<int>(matrix[0].size(), -1));
        vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));
        for(int i=0;i<matrix.size();++i){
            for(int j=0;j<matrix[0].size();++j){
                res=max(res, longestIncreasingPath(matrix, visited, memo, i, j)+1);
            }
        }
        return res;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix, vector<vector<bool>>& visited, vector<vector<int>> &memo, int x, int y) {
        int res=0,tmp=0;
        if(x-1>=0&&visited[x-1][y]==false&&matrix[x][y]<matrix[x-1][y]){
            visited[x-1][y]=true;
            if(memo[x-1][y]==-1)
                memo[x-1][y]=longestIncreasingPath(matrix, visited, memo, x-1, y);
            tmp=max(tmp, memo[x-1][y]+1);
            visited[x-1][y]=false;
        }
        if(x+1<matrix.size()&&visited[x+1][y]==false&&matrix[x][y]<matrix[x+1][y]){
            visited[x+1][y]=true;
            if(memo[x+1][y]==-1)
                memo[x+1][y]=longestIncreasingPath(matrix, visited, memo, x+1, y);
            tmp=max(tmp, memo[x+1][y]+1);
            visited[x+1][y]=false;
        }
        if(y-1>=0&&visited[x][y-1]==false&&matrix[x][y]<matrix[x][y-1]){
            visited[x][y-1]=true;
            if(memo[x][y-1]==-1)
                memo[x][y-1]=longestIncreasingPath(matrix, visited, memo, x, y-1);
            tmp=max(tmp, memo[x][y-1]+1);
            visited[x][y-1]=false;
        }
        if(y+1<matrix[0].size()&&visited[x][y+1]==false&&matrix[x][y]<matrix[x][y+1]){
            visited[x][y+1]=true;
            if(memo[x][y+1]==-1)
                memo[x][y+1]=longestIncreasingPath(matrix, visited, memo, x, y+1);
            tmp=max(tmp, memo[x][y+1]+1);
            visited[x][y+1]=false;
        }
        return tmp;
    }
};

// dp with topological sort
class Solution {
public:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int rows, columns;

    int longestIncreasingPath(vector<vector<int>> &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        rows = matrix.size();
        columns = matrix[0].size();
        auto outdegrees = vector<vector<int>>(rows, vector<int>(columns));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                for (int k = 0; k < 4; ++k) {
                    int newRow = i + dirs[k][0], newColumn = j + dirs[k][1];
                    if (newRow >= 0 && newRow < rows && newColumn >= 0 && newColumn < columns && matrix[newRow][newColumn] > matrix[i][j]) {
                        ++outdegrees[i][j];
                    }
                }
            }
        }
        queue <pair<int, int>> q;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                if (outdegrees[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        int ans = 0;
        while (!q.empty()) {
            ++ans;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto cell = q.front(); q.pop();
                int row = cell.first, column = cell.second;
                for (int k = 0; k < 4; ++k) {
                    int newRow = row + dirs[k][0], newColumn = column + dirs[k][1];
                    if (newRow >= 0 && newRow < rows && newColumn >= 0 && newColumn < columns && matrix[newRow][newColumn] < matrix[row][column]) {
                        --outdegrees[newRow][newColumn];
                        if (outdegrees[newRow][newColumn] == 0) {
                            q.push({newRow, newColumn});
                        }
                    }
                }
            }
        }
        return ans;
    }
};