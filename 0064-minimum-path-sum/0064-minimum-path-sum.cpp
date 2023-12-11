class Solution {
private:
    int solve(int i,int j,vector<vector<int>>& grid,int &n,int &m,vector<vector<int>> &dp){
        if(i==0 && j==0)return grid[i][j];
        if(i<0 || j<0)return 1e9;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j] = grid[i][j] + min(solve(i-1,j,grid,n,m,dp),solve(i,j-1,grid,n,m,dp));
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,-1));
        return solve(n-1,m-1,grid,n,m,vis);
    }
};