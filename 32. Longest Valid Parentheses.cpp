class Solution {
public:
    int longestValidParentheses(string s){
        int i,maxlength=0,l=s.size(),left=0,right=0;
        for(i=0;i<l;i++){
            if(s.at(i)=='('){
                left++;
            }else{
                right++;
            }
            if(left==right){
                maxlength=max(maxlength,right*2);
            }else if(right>=left){
                left=right=0;
            }
        }
        left=right=0;
        for(i=l-1;i>=0;i--){
            if(s.at(i)=='('){
                left++;
            }else{
                right++;
            }
            if(left==right){
                maxlength=max(maxlength,left*2);
            }else if(left>=right){
                left=right=0;
            }
        }
        return maxlength;
    }
};