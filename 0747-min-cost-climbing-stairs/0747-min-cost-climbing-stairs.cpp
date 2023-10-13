class Solution {
private:
    int solve(int i,vector<int>&cost,vector<int> &dp){
        if(i>=cost.size())return 0;
        else if(i==cost.size()-1)return cost[cost.size()-1];
        if(dp[i]!=-1)return dp[i];
        return dp[i] = min(cost[i]+solve(i+1,cost,dp),cost[i]+solve(i+2,cost,dp));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        return min(solve(0,cost,dp),solve(1,cost,dp));
    }
};