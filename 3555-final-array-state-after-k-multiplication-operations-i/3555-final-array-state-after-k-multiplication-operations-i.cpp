class Solution {
private:
    typedef long long ll;
    typedef pair<ll,ll> pll;
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        vector<pll> a;
        int n = nums.size();
        priority_queue<pll,vector<pll>,greater<pll>> pq;
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        while(k--){
            auto [num,i] = pq.top();
            pq.pop();
            num*=multiplier;
            pq.push({num,i});
        }
        while(!pq.empty()){
            auto [num,i] = pq.top();
            pq.pop();
            nums[i] = num;
        }
        return nums;
    }   
};