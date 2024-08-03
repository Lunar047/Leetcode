class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        int row = 0,col = 0;
        // cout<<(m>>1)<<" "<<(n>>1);
        for(int i=0;i<n;i++){
            for(int j=0;j<(m>>1);j++){
                if(grid[i][j]^grid[i][m-j-1])row++;
            }
        }
        for(int j=0;j<m;j++){
            for(int i=0;i<(n>>1);i++){
                if(grid[i][j]^grid[n-1-i][j])col++;
            }
        }
        return min(row,col);
    }   
};