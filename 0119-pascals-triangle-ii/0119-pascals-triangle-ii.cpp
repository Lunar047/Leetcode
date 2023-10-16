class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n = rowIndex;
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=i;j++){
                if(!j || j==i)dp[i][j] = 1;
                else dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
            }
        }
        // for(auto it:dp){
        //     for(auto iz:it)
        //         cout<<iz<<" ";
        //         cout<<endl;
        // }
        vector<int> ans(dp[n].begin(),dp[n].end());
        return ans;
        // return (dp[n].begin(),dp[n].end());
    }
};