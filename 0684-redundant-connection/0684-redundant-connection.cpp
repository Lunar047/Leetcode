class Solution {
private:
    vector<int> parent;
    int findParent(int node){
        // cout<<node<<" ";
        if(parent[node]==node)return node;
        else return parent[node] = findParent(parent[node]);
    }
    bool join(int u,int v){
        int up = findParent(u), vp = findParent(v);
        if(up==vp)return 1;
        parent[up] = vp;
        return 0;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n);
        for(int i=0;i<n;i++)parent[i] = i;
        for(auto &i:edges){
            if(join(i[0]-1,i[1]-1))return i;
        }
        return {-1,-1};
    }
};