class Solution {
private:
    typedef long long int ll;
    ll mod = 1e9+7;
    int n;
    ll solve(int i,int prev1,int prev2,vector<int>&nums,vector<vector<vector<ll>>> &dp){
        if(i>=n)return 1;
        if(dp[i][prev1][prev2] !=-1) return dp[i][prev1][prev2];
        ll ans = 0;
        for(int idx = prev1;idx<=nums[i];idx++){
            int a2 = nums[i] - idx;
            if(a2>=0 && a2<=prev2){
                ans += (solve(i+1,idx,a2,nums,dp)%mod);
            }
        }
        return dp[i][prev1][prev2] = ans%mod;
    }
     ll solve2(int i,int prev1,int prev2,vector<int>&nums,vector<vector<ll>> &dp){
        if(i>=n)return 1;
        if(dp[i][prev1] !=-1) return dp[i][prev1];
        ll ans = 0;
        for(int idx = prev1;idx<=nums[i];idx++){
            int a2 = nums[i] - idx;
            if(a2>=0 && a2<=prev2){
                ans += (solve2(i+1,idx,a2,nums,dp)%mod);
            }
        }
        return dp[i][prev1] = ans%mod;
    }
    // void solve3(int i,int prev1,int prev2,vector<int> &nums,vector<vector<ll>> &dp){
    //     if(i>=n)return;
    //     for(int idx = prev1;idx<=nums[i];idx++){
    //         int a2 = nums[i] - idx;
    //         if(a2>=0 && a2<=prev2){
    //             dp[i][idx] += dp[i-1][]
    //         }
    //     }
    // }
public:
    int countOfPairs(vector<int>& nums) {
        n = nums.size();
        // vector<vector<vector<ll>>> dp(1002,vector<vector<ll>>(52,vector<ll>(52,0)));
        vector<vector<ll>> dp(2001,vector<ll>(52,0));
        // return solve2(0,0,nums[0],nums,dp2)%mod;
        // return solve(0,0,nums[0],nums,dp)%mod;
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
        // for(int i= 0;i<n;i++){
        //     for(int j = 0;j<=nums[i];j++)cout<<dp[i][j]<<" ";cout<<endl;
        // }
        ll ans = 0;
        for(int i = 0;i<=nums[n-1];i++){
            ans += dp[n-1][i];
            ans%=mod;
        }
        return ans%mod;
    }
};