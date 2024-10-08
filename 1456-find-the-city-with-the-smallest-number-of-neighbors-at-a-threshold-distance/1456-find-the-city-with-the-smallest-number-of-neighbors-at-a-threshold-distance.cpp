class Solution {
private:
    #define inf INT_MAX
    #define ll long long
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<ll>> dist(n,vector<ll>(n,inf));
        for(auto &i:edges){
            dist[i[0]][i[1]] = i[2];
            dist[i[1]][i[0]] = i[2];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k = 0;k<n;k++){
                    if(dist[j][i]==inf || dist[k][i]==inf)continue;
                    dist[j][k] = min(dist[j][k],dist[j][i]+dist[k][i]);
                }
            }
        }
        int city = -1,cnt = inf;
        for(int i=0;i<n;i++){
            int cur = 0;
            for(int j=0;j<n;j++){
                if(i==j)continue;
                if(dist[i][j]<=distanceThreshold)cur++;
            }
            if(cur<=cnt){
                cnt = cur;
                city = i;
            }
        }
        return city;
    }
};