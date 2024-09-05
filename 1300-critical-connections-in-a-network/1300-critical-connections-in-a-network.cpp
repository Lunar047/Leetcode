class Solution {
private:    
    vector<int> Tin,low,vis;
    vector<vector<int>> bridges;
    void out(vector<int>&a){for(auto &i:a)cout<<i<<" ";cout<<endl;}
    int timer = 0;
    void dfs(int node,int parent,vector<int> adj[]){
        // cout<<node<<" :";
        vis[node] = 1;
        Tin[node] = low[node] =  timer++;
        bool parent_skipped = false;
        for(auto &i:adj[node]){
             if (i == parent && !parent_skipped) {
                parent_skipped = true;
                continue;
            }
            if(vis[i]){
                low[node] = min(low[node],low[i]);
            }
            else{
                dfs(i, node,adj);
                low[node] = min(low[node], low[i]);
                if (low[i] > Tin[node])
                    bridges.push_back({i,node});
            }
            // if(!vis[i]){
            //     // cout<<i<<" ";
            //     // vis[i] = 1;
            //     dfs(i,node,adj);
            //     low[node] = min(low[node],low[i]);
            //     if(low[i]>low[node]){
            //     // cout<<i<<" "<<node<<endl;
            //         bridges.push_back({node,i});
            //     }
            // }
            // else if(i!=parent){
            //     low[node] = min(low[node],low[i]);
            //     // if(low[i]>low[node]) bridges.push_back({node,i});
            // }
           
        }
        // cout<<endl;
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto &i:connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        // for(int i=0;i<n;i++){
        //     for(auto &i:adj[i])cout<<i<<" ";cout<<endl;
        // }
        Tin.resize(n,0);
        low.resize(n,1e9);
        vis.resize(n,0);
        // vis[0] = 1;
        dfs(0,-1,adj);
        // out(Tin);
        out(low);
        // out(vis);
        return bridges;
    }
};