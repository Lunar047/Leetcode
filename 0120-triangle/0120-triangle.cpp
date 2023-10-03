class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                if(i)
                if(!j){
                    triangle[i][j] +=triangle[i-1][j];
                }
                else if(j==i)  triangle[i][j] +=triangle[i-1][j-1];
                else  triangle[i][j] += min(triangle[i-1][j],triangle[i-1][j-1]);        
                if(i==n-1) ans = min(ans,triangle[i][j]);
           }
        }
        return ans;
    }
};