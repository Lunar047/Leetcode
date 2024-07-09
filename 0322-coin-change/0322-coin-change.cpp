class Solution {
private:
    int solve(int i,vector<int>& coins, int amount,vector<vector<int>> &dp){
        if(i<0){
            if(amount==0)return 0;
            else return 1e8;
        }
        if(amount==0)return 0;
        if(amount<0) return 1e8;
        if(dp[i][amount]!=-1)return dp[i][amount];
        int ntake = solve(i-1,coins,amount,dp);
        int take = 1 + solve(i,coins,amount-coins[i],dp);
        return dp[i][amount] = min(take,ntake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int a = solve(n-1,coins,amount,dp);
        return a==1e8?-1:a;
    }
};