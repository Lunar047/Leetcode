class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        int k = queries.size();
        vector<int> dist(n,0),ans;
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            dist[i] = i;
            if(i)adj[i].push_back(i-1);
        }
        for(int i=0;i<k;i++){
            int u = queries[i][0],v = queries[i][1];
            adj[v].push_back(u);
            if(dist[v]>dist[u]+1){
                dist[v] = dist[u]+1;
                for(int j=v+1;j<n;j++){
                    for(auto &it:adj[j]){
                        dist[j] = min(dist[j],1+dist[it]);
                    }
                }
            }
            ans.push_back(dist[n-1]);
        }
        return ans;
    }
};