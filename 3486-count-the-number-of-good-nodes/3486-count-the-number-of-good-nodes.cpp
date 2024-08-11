class Solution {
private:   
    vector<int> child;
    int ans = 0;
    int solve(int node,int parent,vector<int>adj[]){
        // cout<<node<<" ";
        int sz = - 1;
        bool f = 1;
        for(auto &i:adj[node]){
            if(i==parent)continue;
            child[i] = solve(i,node,adj);
            if(sz ==-1)sz = child[i];
            if(sz!=child[i])f = 0;
            child[node] += child[i];
        }
        if(f)ans++;
        return 1+child[node];
    }
public:

    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size();
        n++;
        child.resize(n,0);
        vector<int> adj[n];
        for(auto &i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        child[0] = solve(0,-1,adj);
        // for(auto &i:child)cout<<i<<" ";cout<<endl;
        // for(int i=0;i<n;i++){
        //     // cout<<i<<" ";
        //     bool f =1;
        //     int sz = -1;
        //     for(auto &it:adj[i]){
        //         if(i==it)continue;
        //         if(sz==-1)sz = child[it];
        //         else if(sz!=child[it])f = 0;
        //     }
        //     if(f)ans++;
        //     // cout<<f<<" ";
        // }
        return ans;
    }
};