class Solution {
private:
  int f(int i,int j,vector<vector<int>>&Grid, vector<vector<long>> &dp){
    if(i>=0 && j>=0 && Grid[i][j])return 0;
    else if(i==0 && j==0)return 1;
    else if(i<0 || j<0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int up = f(i-1,j,Grid,dp);
    int left = f(i,j-1,Grid,dp);
    return dp[i][j]=up+left;
  }
public:

    // long  solve(int i,int j,int &r, int &c,vector<vector<int>>& Grid,vector<vector<long>> &dp)
    // {
    //     if(Grid[i][j]==1 || i>=r || j>=c)return 0;
    //     else if(i==r-1 || j== c-1)return 1+dp[i][j];
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     long right = solve(i,j+1,r,c,Grid,dp);
    //     long down = solve(i+1,j,r,c,Grid,dp);
    //     return dp[i][j] = right+down;
    // }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      int n = obstacleGrid.size();
      int m = obstacleGrid[0].size();
      vector<vector<long>> dp(n,vector<long>(m,-1));
      // solve(0,0,n,m,obstacleGrid,dp);
      // return dp[n-1][m-1];
      return f(n-1,m-1,obstacleGrid,dp);
    }
};
