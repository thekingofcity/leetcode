class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        if(n<=0){
            ret.push_back("");
            return ret;
        }
        string s="(";
        dfs(ret, 1, 0, n, s);
        return ret;
    }
     void dfs(vector<string> &ret, int l, int r, int n, string &s){
         // cout<<l<<r<<n<<endl;
         if(l==r&&r==n){
             ret.push_back(s);
             return;
         }
         if(l>n||r>n||r>l) return;
         
         s+='(';
         dfs(ret, l+1, r, n, s);
         s.pop_back();
         s+=')';
         dfs(ret, l, r+1, n, s);
         s.pop_back();
         
     }
};