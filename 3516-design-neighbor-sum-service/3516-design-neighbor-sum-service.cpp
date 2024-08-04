class neighborSum {
private:
     vector<vector<int>> g;
     int n,m;
public:
    neighborSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        for(int i=0;i<n;i++){
            vector<int> temp;
            for(int j=0;j<m;j++)temp.push_back(grid[i][j]);
            g.push_back(temp);
        }
        
    }
    
    int adjacentSum(int value) {
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(g[i][j]==value){
                    if(i)ans+= g[i-1][j];
                    if(j>0)ans+=g[i][j-1];
                    if(i<n-1)ans+=g[i+1][j];
                    if(j<m-1)ans+=g[i][j+1];
                    break;
                }
            }
        }
        return ans;
    }
    
    int diagonalSum(int value) {
        int ans =0;
          for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(g[i][j]==value){
                    if(i && j)ans+= g[i-1][j-1];
                    if(i && j<m-1)ans+=g[i-1][j+1];
                    if(i<n-1 && j)ans+=g[i+1][j-1];
                    if(i<n-1 && j<m-1)ans+=g[i+1][j+1];
                    break;
                }
            }
        }
        return ans;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */