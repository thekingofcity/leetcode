// https://leetcode.com/problems/different-ways-to-add-parentheses/discuss/66331/C%2B%2B-4ms-Recursive-and-DP-solution-with-brief-explanation
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        for(int i=0;i<input.size();i++){
            if(!isdigit(input[i])){
                auto left=diffWaysToCompute(input.substr(0,i));
                auto right=diffWaysToCompute(input.substr(i+1));
                for(auto l:left)
                    for(auto r:right)
                        switch(input[i]){
                            case '+': result.push_back(l+r);break;
                            case '-': result.push_back(l-r);break;
                            case '*': result.push_back(l*r);break;
                        }
            }
        }
        if(result.empty())
            result.push_back(atoi(input.c_str()));
        return result;
    }
};