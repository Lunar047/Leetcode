class Solution {
private:
typedef pair<int,double> pid;
typedef pair<double,int> pdi;    
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pid> adj[n];
        int m = edges.size();
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<int> vis(n,0);
        vector<double> prob(n,0);
        prob[start_node] =1;
        priority_queue<pdi> pq;
        pq.push({1,start_node});
        while(!pq.empty()){
            auto [p1,node] = pq.top();
            pq.pop();
            if(vis[node])continue;
            vis[node] =1;
            for(auto &[nxt,p]:adj[node]){
                double d = p *p1;
                if(d>=prob[nxt]){
                    prob[nxt] =d;
                    pq.push({d,nxt});
                }
            }
        }
        return prob[end_node];
    }
};