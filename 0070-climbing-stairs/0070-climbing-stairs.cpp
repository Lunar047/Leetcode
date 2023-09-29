class Solution {
public:
    int solve(int n,vector<int> &dp){
        if(n==0)return 1;
        else if(n<0)return 0;
        if(dp[n]!=-1)return dp[n];
        return dp[n] = solve(n-1,dp)+solve(n-2,dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        dp[0] = 1;
        return solve(n,dp);

    }

//  // This recursion method works perfectly for n = 40 and we need it to be worked for 45
//     int climbStairs(int n) {
//         if(n<=0)
//        {
//         if(n==0)
//             return 1;
//         return 0;
//        }
//      return  climbStairs(n-1) + climbStairs(n-2);
        
//     }
};
