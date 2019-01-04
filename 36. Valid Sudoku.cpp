class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // print(board);
        // return true;
        bool valid[9]={false};
        int i,j,temp;
        char c;
        // check row
        for(i=0;i<9;i++){
            for(temp=0;temp<9;temp++){
                valid[temp]=false;
            }
            for(j=0;j<9;j++){
                c=board[i][j]-'1';
                if(c==-3) continue;
                if(valid[c]==true){
                    return false;
                }else{
                    valid[c]=true;
                }
            }
        }
        // check column
        for(j=0;j<9;j++){
            for(temp=0;temp<9;temp++){
                valid[temp]=false;
            }
            for(i=0;i<9;i++){
                c=board[i][j]-'1';
                if(c==-3) continue;
                if(valid[c]==true){
                    return false;
                }else{
                    valid[c]=true;
                }
            }
        }
        // check 3x3
        int k,l;
        for(k=0;k<9;k=k+3){
            for(l=0;l<9;l=l+3){
                for(temp=0;temp<9;temp++){
                    valid[temp]=false;
                }
                
                for(i=0;i<3;i++){
                    for(j=0;j<3;j++){
                        c=board[i+k][j+l]-'1';
                        if(c==-3) continue;
                        if(valid[c]==true){
                            return false;
                        }else{
                            valid[c]=true;
                        }
                    }
                }
            }
        }
        return true;
    }
    void print(vector<vector<char>>& board){
        int i,j;
        for(i=0;i<9;i++){
            for(j=0;j<9;j++){
                if(board[i][j]=='.'){cout<<'0';}
                else{cout<<board[i][j];}
            }
            cout<<endl;
        }
    }
};