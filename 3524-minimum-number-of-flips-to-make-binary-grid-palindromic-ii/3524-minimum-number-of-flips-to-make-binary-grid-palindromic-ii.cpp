class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        // if(n<3 && m<3)return base(n,m,grid);
        int ans = 0;
        for(int i=0;i<(n>>1);i++){
            for(int j = 0;j<(m>>1);j++){
                int sum = grid[i][j] +grid[n-i-1][j] + grid[i][m-1-j] + grid[n-i-1][m-1-j];
                ans += min(sum,4-sum);
            }
        }
        int double1=0,single1= 0;
        if(n&1 && m&1){
            if(grid[n>>1][m>>1])ans++;
        }
        if(n&1){
            for(int j=0;j<(m>>1);j++){
                if(grid[n>>1][j]^grid[n>>1][m-1-j]){
                    ans++;
                    single1++;
                }
                else if(grid[n>>1][j])double1+=2;
            }
        }
        if(m&1){
            for(int i=0;i<(n>>1);i++){
                if(grid[i][m>>1]^grid[n-1-i][m>>1]){
                    ans++;
                    single1++;
                }
                else if(grid[i][m>>1])double1+=2;
            }
        }
        if(double1%4==2 && !single1)ans+=2;
        return ans;
    }
};