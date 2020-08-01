class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int K=0;
public:
    KthLargest(int k, vector<int>& nums) {
        for(auto num:nums){
            pq.push(num);
            if(pq.size()>k)
                pq.pop();
        }
        K=k;
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>K)
            pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */