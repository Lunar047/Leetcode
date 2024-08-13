class Solution {
private:
    typedef long long int ll;
    ll mod = 1e9+7;
    int n;
public:
    int countOfPairs(vector<int>& nums) {
        n = nums.size();
        vector<vector<ll>> dp(2001,vector<ll>(52,0));
        for(int i=0;i<=nums[0];i++){
           dp[0][i] = 1;
        }
        for(int index = 0;index<n-1;index++){
            for(int i = 0;i<=nums[index];i++){
                int j = nums[index] - i;
                for(int k = i;k<=nums[index+1];k++){
                    int l = nums[index+1]- k;
                    if(l<=j){
                        dp[index+1][k]+=dp[index][i];
                        dp[index+1][k]%=mod;
                    }
                }
            }
        }
        ll ans = 0;
        for(int i = 0;i<=nums[n-1];i++){
            ans += dp[n-1][i];
            ans%=mod;
        }
        return ans%mod;
    }
};