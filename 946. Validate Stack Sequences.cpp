class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int i=0,j=0;
        while(i<pushed.size()||j<popped.size()){
            if(s.size()&&j<popped.size()&&s.top()==popped[j]){
                s.pop();
                j++;
            }else{
                if(i>=pushed.size()) return false;
                s.push(pushed[i++]);
            }
        }
        return true;
    }
};