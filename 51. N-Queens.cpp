class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> row(n, false), col(n, false), x(2*n-1, false), y(2*n-1, false);
        vector<vector<string>> ret;
        vector<vector<bool>> board(n, vector<bool>(n, false));
        dfs(board, row, col, x, y, ret, n, 0);
        return ret;
    }
    
    void dfs(vector<vector<bool>>& board, vector<bool>& row, vector<bool>& col, vector<bool>& x, vector<bool>& y, vector<vector<string>>& ret, int n, int cur){
        if(cur==n){
            vector<string> temp;
            for(auto line:board){
                string tmp="";
                for(auto x:line)
                    tmp+=x==true?'Q':'.';
                temp.push_back(tmp);
            }
            ret.push_back(temp);
            return;
        }
        
        for(int i=0;i<n;++i){
            int j=cur;
            // for(int j=0;j<n;++j){
                if(row[i]==false&&col[j]==false&&x[j+i]==false&&y[n-1-i+j]==false){
                row[i]=true; col[j]=true; x[j+i]=true; y[n-1-i+j]=true;
                board[i][j]=true;
                dfs(board, row, col, x, y, ret, n, cur+1);
                board[i][j]=false;
                row[i]=false; col[j]=false; x[j+i]=false; y[n-1-i+j]=false;
                }
            // }
        }
    }
};