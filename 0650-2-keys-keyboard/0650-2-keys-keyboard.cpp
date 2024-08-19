class Solution {
private:
    typedef long long ll;
public:
    int minSteps(int n) {
        vector<int> dp(1004,0);
        dp[2] = 2;
        for(int i=3;i<=n;i++) dp[i] = 1 + dp[i-1];
        // for(int i=0;i<=n;i++)cout<<dp[i]<<" ";
        for(int i=2;i<=n;i++){
            for(int j = 1;j<=i/2;j++){
                if(i%j==0)dp[i] = min(dp[i],dp[j]+i/j);
            }
        }
        // cout<<dp[n-1]<<" "<<dp[n+1];
        return dp[n];
    }
};