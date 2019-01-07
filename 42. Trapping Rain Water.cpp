// remember to comment cout, this will cost a lot of running time
// 60ms -> 8ms
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==0) return 0;
        auto maxPosition = max_element(height.begin(), height.end());
        // cout<<maxPosition-height.begin()<<endl;
        int water=trapleft(height, 0, maxPosition-height.begin());
        // cout<<endl;
        water+=trapright(height, maxPosition-height.begin(), height.size()-1);
        return water;
    }
    int trapleft(vector<int>& height, int left, int right){
        // cout<<left<<" "<<right<<endl;
        int currentHeight=height[0],water=0,currentWater=0,i,l;
        for(i=left;i<=right;i++){
            if(height[i]>=currentHeight){
                water=water+currentWater;
                currentWater=0;
                currentHeight=height[i];
            }else{
                currentWater=currentWater+currentHeight-height[i];
                // cout<<i<<" "<<currentHeight-height[i]<<endl;
            }
        }
        return water;
    }
    int trapright(vector<int>& height, int left, int right){
        // cout<<left<<" "<<right<<endl;
        int currentHeight=height[right],water=0,currentWater=0,i,l;
        for(i=right;i>=left;i--){
            if(height[i]>=currentHeight){
                water=water+currentWater;
                currentWater=0;
                currentHeight=height[i];
            }else{
                currentWater=currentWater+currentHeight-height[i];
                // cout<<i<<" "<<currentHeight-height[i]<<endl;
            }
        }
        return water;
    }
};