class Solution {
private:
    const int mod = 1e9+7;
    long long solve(int idx,int steps,int &n,vector<vector<long long>> &dp){
        if(idx==0 && steps==0)return 1;
        else if(idx<0 || idx>=n || steps<=0)return 0;
        if(dp[idx][steps]!=-1)return dp[idx][steps];
        return dp[idx][steps] =((solve(idx+1,steps-1,n,dp)%mod)+(solve(idx,steps-1,n,dp)%mod)+(solve(idx-1,steps-1,n,dp)%mod))%mod;
    }
public:
    int numWays(int steps, int arrLen) {
        vector<vector<long long>> dp(steps+1,vector<long long>(steps+1,-1));
        return solve(0,steps,arrLen,dp);
    }
};