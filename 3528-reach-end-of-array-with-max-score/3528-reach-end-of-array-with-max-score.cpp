class Solution {
private:
    typedef long long int ll;
public:
    long long findMaximumScore(vector<int>& nums) {
        int n = nums.size();
        // vector<ll> dp(n+2,0);
        if(n==1)return 0;
        ll ans = 0,mx = nums[0],prev = nums[0];
        for(int i=1;i<n;i++){
            ans+=mx;
            if(nums[i]>mx)mx = nums[i];
        }
        return ans;
    }
};