class Solution {
private:
    int dr[4] = {0,1,0,-1}, dc[4] = {1,0,-1,0};
    int n,m;
    int bfs(int i,int j,vector<vector<int>> &grid){
        int cnt = 0;
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            auto [i,j] = q.front();q.pop();
            for(int k=0;k<4;k++){
                int ni = i+dr[k],nj = j + dc[k];
                if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]){
                    cnt++;
                    q.push({ni,nj});
                    grid[ni][nj] = 0;
                }
            }
        }
        if(!cnt)return 1;
        return cnt;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size(),m = grid[0].size();
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j])ans = max(ans,bfs(i,j,grid));
            }
        }
        return ans;
    }
};