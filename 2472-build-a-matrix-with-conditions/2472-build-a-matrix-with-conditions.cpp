class Solution {
private:
    vector<int> topoSort(vector<vector<int>> &edge,int n){
        vector<int> deg(n,0);
        vector<int> adj[n];
        for(auto &i:edge){
            adj[i[0]-1].push_back(i[1]-1);
            adj[i[1]-1].push_back(i[0]-1);
            deg[i[1]-1]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(deg[i]==0)q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node+1);
            q.pop();
            // if(vis[node])continue;
            // vis[node]=1;
            for(auto &i:adj[node]){
                deg[i]--;
                if(deg[i]==0)q.push(i);
            }
        }
        return ans;
    }
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> row = topoSort(rowConditions,k),col = topoSort(colConditions,k);
        if(row.size()<k || col.size()<k)return {};
        vector<vector<int>> ans(k,vector<int>(k,0));
        // for(auto &i:row)cout<<i<<" ";
        // cout<<endl;
        // for(auto &i:col)cout<<i<<" ";
        // cout<<endl;
        map<int,int> mp;
        for(int i=0;i<k;i++){
            ans[i][0] = row[i];
            mp[row[i]] = i;
        }
        for(int j=0;j<k;j++){
            int i =  mp[col[j]];
            swap(ans[i][0],ans[i][j]);
        }
        return ans;
    }
};