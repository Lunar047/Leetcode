class Solution {
private:
    int dr[4] = {0,1,0,-1},dc[4] = {1,0,-1,0};
    typedef pair<int,int> pii;
    int n,m;
    bool bfs(int i1,int j1,vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        queue<pii> q;
        q.push({i1,j1});
        bool f = grid1[i1][j1];
        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();
            for(int k = 0;k<4;k++){
                int ni = i+dr[k],nj = j+dc[k];
                if(ni>=0 && ni<n && nj>=0 && nj<m && grid2[ni][nj]){
                    grid2[ni][nj] = 0;
                    if(f && !grid1[ni][nj])f = 0;
                    q.push({ni,nj});
                }
            }
        }
        return f;
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n = grid1.size();
        m = grid1[0].size();
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]){
                    if(bfs(i,j,grid1,grid2))ans++;
                }
            }
        }
        return ans;
    }
};