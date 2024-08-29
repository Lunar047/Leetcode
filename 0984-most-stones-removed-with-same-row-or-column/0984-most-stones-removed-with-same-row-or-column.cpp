class Solution {
private:
public:
    int removeStones(vector<vector<int>>& stones) {
        vector<int> row[10002],col[10002];
        int n = stones.size();
        for(int i=0;i<n;i++){
            row[stones[i][0]].push_back(i);
            col[stones[i][1]].push_back(i);
        }
        vector<int> vis(n+1,0),parent(n+1,-1);
        int parents = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                parent[i] = parents;
                queue<int> q;
                q.push(i);
                // q.push(stones[i][1]);
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    if(vis[node])continue;
                    vis[node]++;
                    int r =  stones[node][0],c = stones[node][1];
                    for(auto &ij:row[r]){
                        if(!vis[ij]){
                            q.push(ij);
                            parent[ij] = parents;
                        }
                    }
                    for(auto &ij:col[c]){
                        if(!vis[ij]){
                            q.push(ij);
                            parent[ij] = parents;
                        }
                    }
                }
                parents++;
            }
        }
        // for(int i=0;i<n;i++)cout<<parent[i]<<" ";cout<<endl;
        vector<int> freq(n+1,0);
        for(auto &i:parent)if(i>=0)freq[i]++;
        int ans = 0;
        for(auto &i:freq){
            if(i>0)ans+=(i-1);
        }
        // return *max_element(freq.begin(),freq.end()) -1;
        return ans;
    }
};