class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.empty()) return true;
        if(board.empty()||board[0].empty()) return false;
        vector<vector<bool>> isUsed(board.size(), vector<bool>(board[0].size(), false));

        string current="";
        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[0].size();++j){
                if(existCore(board, word, 0, i, j, isUsed, current))
                    return true;
            }
        }
        return false;
    }
    
    bool existCore(vector<vector<char>>& board, string &word, int index,
                   int x, int y, vector<vector<bool>>& isUsed,
                   string &current){
        // see Line 31 for reason
        // if(word.compare(current)==0) return true;
        bool ret=false;
        if(isUsed[x][y]==false&&board[x][y]==word.at(index)){
            isUsed[x][y]=true;
            current.push_back(word.at(index));
            ++index;
            // check here to avoid the last test case error
            if(word.compare(current)==0) return true;
            // 下
            if(x+1<board.size()){
                ret=existCore(board, word, index, x+1, y, isUsed, current);
                if(ret) return ret;
            }
            // 上
            if(x-1>=0){
                ret=existCore(board, word, index, x-1, y, isUsed, current);
                if(ret) return ret;
            }
            // 右
            if(y+1<board[0].size()){
                ret=existCore(board, word, index, x, y+1, isUsed, current);
                if(ret) return ret;
            }
            // 左
            if(y-1>=0){
                ret=existCore(board, word, index, x, y-1, isUsed, current);
                if(ret) return ret;
            }
            current.pop_back();
            --index;
            isUsed[x][y]=false;
        }
        return ret;
    }
};
/*
[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
"ABCCED"
[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
"SEE"
[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
"ABCB"
[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
""
[["a"]]
"a"
*/