/*
LOL
https://leetcode.com/problems/combination-sum-iv/discuss/228568/C++-0ms-100-DP-solution-w-explanation-and-answers-for-follow-up-questions/233730
*/
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n=target+1,l=nums.size();
        vector<unsigned long> dp(n, 0);
        for(int i=1;i<n;++i){
            unsigned long cur=0;
            for(int j=0;j<l;++j){
                int temp=i-nums[j];
                if(temp==0){
                    ++cur;
                }else if(temp>0){
                    cur+=dp[temp];
                }
            }
            // cout<<i<<' '<<cur<<endl;
            dp[i]=cur;
        }
        return dp[target];
    }
};
/*
[1,2,3]
4
[1,2,5,3]
8
[]
10
[1]
10
[3,33,333]
10000
[10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,370,380,390,400,410,420,430,440,450,460,470,480,490,500,510,520,530,540,550,560,570,580,590,600,610,620,630,640,650,660,670,680,690,700,710,720,730,740,750,760,770,780,790,800,810,820,830,840,850,860,870,880,890,900,910,920,930,940,950,960,970,980,990,111]
999
*/