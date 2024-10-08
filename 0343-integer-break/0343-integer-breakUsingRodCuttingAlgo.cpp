class Solution {
public:
    int integerBreak(int n) {
        vector<vector<int>> dp(n,vector<int>(n+1,1));
        for(int i=1;i<n;i++){
            for(int j=1;j<=n;j++){
                if(j<i)dp[i][j] = dp[i-1][j];
                else if(i==j)dp[i][j] = max(dp[i-1][j],j);
                else{
                    dp[i][j] = max(i*dp[i][j-i],dp[i-1][j]);
                }
            }
        }
        return dp[n-1][n];
    }
};
