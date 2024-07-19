class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size(),m = matrix[0].size();
        vector<int> rowmax(n, INT_MAX);
        vector<int> colmax(m,INT_MIN);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                rowmax[i] = min(rowmax[i],matrix[i][j]);
                colmax[j] = max(colmax[j],matrix[i][j]);
            }
        }
        // for(int i=0;i<n;i++)cout<<rowmax[i]<<" ";
        // cout<<endl;
        // for(int j=0;j<m;j++)cout<<colmax[j]<<" ";
        vector<int> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(rowmax[i]==colmax[j])ans.push_back(rowmax[i]);
            }
        }
        return ans;
    }
};