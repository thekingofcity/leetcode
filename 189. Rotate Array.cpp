class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        rotate2(nums, k);
    }
    void rotate1(vector<int>& nums, int k) {
        int l=nums.size();
        vector<int> n(l);
        for(int i=l-k,j=0;i<l;i++,j++)
            n[j]=nums[i];
        for(int i=0,j=k;j<l;i++,j++)
            n[j]=nums[i];
        nums=n;
    }
    void rotate2(vector<int>& nums, int k) {
        int count = 0;
        for (int start = 0; count < nums.size(); start++) {
            int current = start;
            int prev = nums[start];
            do {
                int next = (current + k) % nums.size();
                swap(nums[next], prev);
                current = next;
                count++;
            } while (start != current);
        }
    }
    void rotate3(vector<int>& nums, int k) {
        auto b=nums.begin();
        reverse(b,nums.end());
        reverse(b,b+k);
        reverse(b+k,nums.end());
    }
};