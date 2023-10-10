class Solution {
private:
    int solve(int n,vector<int>&dp){
        if(n<=3)return n;
        if(dp[n])return dp[n];
        int ans =0;
        for(int i=2;i<n;i++){
            ans = max(ans,i*solve(n-i,dp));
        }
        return dp[n]=ans;
    }
public:
    int integerBreak(int n) {
        if(n<=3)return n-1;
        vector<int> dp(n+1,0);
        return solve(n,dp);
    }
};