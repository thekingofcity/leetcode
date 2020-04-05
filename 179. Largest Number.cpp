class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numss(nums.size());
        for(int i=0;i<nums.size();i++)
            numss[i]=to_string(nums[i]);

        sort(numss.begin(), numss.end(), cmp);
        
        if(numss[0]=="0") return "0";
        
        string ret="";
        for(int i=0;i<numss.size();i++)
            ret+=numss[i];
        return ret;
    }
    
    static bool cmp(string &a, string &b){
        string c=a+b;
        string d=b+a;
        return c>d;
    }
};