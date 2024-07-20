class Solution {
private:
    typedef pair<int,int> pii;
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size(),m = colSum.size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        priority_queue<pii,vector<pii>,greater_equal<pii>> pq1,pq2;
        for(int i=0;i<n;i++){
            pq1.push({rowSum[i],i});
        }
        for(int i=0;i<m;i++){
            pq2.push({colSum[i],i});
        }
        while(!pq1.empty() && !pq2.empty()){
            auto [row,i] = pq1.top();
            auto [col,j] = pq2.top();
            pq1.pop();
            pq2.pop();
            ans[i][j] = min(row,col);
            if(row>col){
                pq1.push({row-col,i});
            }
            else pq2.push({col-row,j});

        }
        return ans;
    }
};