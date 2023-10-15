class Solution {
private:
  long long solve(long long n,unordered_map<long long,long long>&dp) {
        if(n<=1)return 0;
        if(dp.count(n))return dp[n];
        if(n&1){
            return dp[n] = min(1+solve(n-1,dp),1+solve(n+1,dp));
        }
        else return dp[n]= 1+solve(n/2,dp);
    }
public:
    int integerReplacement(int n) {
        unordered_map<long long,long long> dp;
        return solve((long long )n,dp);
    }
};