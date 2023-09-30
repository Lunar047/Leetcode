class Solution {
public:
// int uniquePaths(int m, int n) {
//   if(m==1 || n==1)return 1;
//   else return uniquePaths(m-1,n)+uniquePaths(m,n-1);
// }

// vector<vector<int>> dp(101,vector<int>(101,-1));
int solve(int m,int n,vector<vector<int>> &dp){
if(m==1 || n==1)return 1;
  if(dp[m][n]!=-1)return dp[m][n];
  else return dp[m][n]=solve(m-1,n,dp)+solve(m,n-1,dp);
}
int uniquePaths(int m, int n) {
  vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
  return solve(m,n,dp);
}
//  void solve(int x,int y,int &r, int &c,long &ans)
//     {
//       if(x == c-1 && y == r -1)
//       {
//         ans ++;
//         return ;
//       }
     
//       if(x+1<c)
//       {
//         solve(x+1,y,r,c,ans);
//       }
//       if(y+1<r)
//       {
//         solve(x,y+1,r,c,ans);
//       }
//     }
//     int uniquePaths(int m, int n) {
//       //   // vector<vector<long long>> dp(m,vector<int>(n,0));
//       // long ans = 0;
//       // solve(0,0,n,m,ans);
//       // return ans;
//     }
};