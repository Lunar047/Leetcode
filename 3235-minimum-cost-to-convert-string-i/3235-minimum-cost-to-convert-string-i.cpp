class Solution {
private:
    typedef long long int lli;
    typedef pair<lli,lli> pii;

public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = source.size(),k = original.size();
        // vector<pii> adj[26];
        vector<vector<lli>> dist(26,vector<lli>(26,INT_MAX));
        for(int i=0;i<k;i++){
            dist[original[i]-'a'][changed[i]-'a'] = min((lli)cost[i],dist[original[i]-'a'][changed[i]-'a']);
        }
        for(int via= 0;via<26;via++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(dist[i][via]==INT_MAX || dist[via][j]==INT_MAX)continue;
                    dist[i][j] = min(dist[i][j],dist[i][via]+dist[via][j]);
                }
            }
        }
        lli ans = 0;
        for(int i=0;i<n;i++){
            if(source[i]^target[i]){
                if(dist[source[i]-'a'][target[i]-'a']==INT_MAX)return -1;
                else ans += dist[source[i]-'a'][target[i]-'a'];
            }
        }
        return ans;
    }
};