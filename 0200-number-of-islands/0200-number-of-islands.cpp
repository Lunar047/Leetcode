class Solution {
private:
    int row[4] = {0,1,-1,0};
    int col[4] = {1,0,0,-1};
    int n,m;
    void dfs(int i,int j,vector<vector<char>> &grid){
        grid[i][j] = '0';
        for(int k=0;k<4;k++){
            int ni = i + row[k],nj = j + col[k];
            if(ni>=0 && nj>=0 && ni<n && nj<m && grid[ni][nj]=='1'){
                dfs(ni,nj,grid);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size(),m = grid[0].size();
        int ans =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(i,j,grid);
                }
            }
        }
        return ans;
    }
};
auto init = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 'c';
}();