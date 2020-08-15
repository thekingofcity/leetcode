// O(n^2*log(k))
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        int n=matrix.size();
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                pq.push(matrix[i][j]);
                if(pq.size()>k) pq.pop();
            }
        }
        return pq.top();
    }
};

// O(nlgX) 其中X为最大值和最小值的差值
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int left=matrix[0][0], right=matrix.back().back(), mid=0;
        while(left<right){
            mid=left+(right-left)/2;
            int cnt=search_less_than(matrix, mid);
            if(cnt>=k) right=mid;
            else left=mid+1;
        }
        return left;
    }
    
    int search_less_than(vector<vector<int>>& matrix, int mid) {
        int n=matrix.size(),i=n-1,j=0,cnt=0;
        while(i>=0&&j<n){
            if(matrix[i][j]>mid)
                --i;
            else{
                cnt+=i+1;
                ++j;
            }
        }
        return cnt;
    }
};