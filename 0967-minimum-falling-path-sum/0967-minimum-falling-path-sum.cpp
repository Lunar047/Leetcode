class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        if(n==1)return *min_element(matrix[0].begin(),matrix[0].end());
        int ans = INT_MAX;
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                if(!j){
                    matrix[i][j] += min(matrix[i-1][j],matrix[i-1][j+1]);
                }
                else if(j==n-1){
                    matrix[i][j] += min(matrix[i-1][j],matrix[i-1][j-1]);
                }
                else{
                    matrix[i][j] += min({matrix[i-1][j],matrix[i-1][j+1],matrix[i-1][j-1]});
                }
                if(i==n-1)ans = min(ans,matrix[i][j]);
            }
        }
        return ans;
    }
};