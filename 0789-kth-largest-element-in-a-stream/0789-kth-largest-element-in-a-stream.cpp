class KthLargest {
private:
    priority_queue<int,vector<int>,greater<int>> pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto &i:nums){
            if(pq.size()<k)pq.push(i);
            else{
                if(pq.top()<i){
                    pq.pop();
                    pq.push(i);
                }
            }
        }
    }
    
    int add(int val) {
        if(pq.size()>=k && pq.top()<val){
            pq.pop();
            pq.push(val);
        }
        else if(pq.size()<k)pq.push(val);
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */