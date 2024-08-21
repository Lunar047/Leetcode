class Solution {
private:
    typedef long long ll;
    int n;
    ll solve(int i,int j,bool f,vector<int>&p,vector<vector<vector<ll>>>&dp){
        if(i>=j)return 0;
        // cout<<f<<" "<<i<<" "<<j<<endl;
        if(dp[f][i][j]!=-1)return dp[f][i][j];
        if(f){
            return  dp[f][i][j] = max(p[i] + solve(i+1,j,!f,p,dp) , p[j] + solve(i,j-1,!f,p,dp));
        }
        else return dp[f][i][j] = max(solve(i+1,j,!f,p,dp) , solve(i,j-1,!f,p,dp));
    }
public:
    bool stoneGame(vector<int>& piles) {
        int i=0,j = piles.size()-1;
        vector<vector<vector<ll>>> dp(2,vector<vector<ll>>(j+1,vector<ll>(j+1,-1)));
        bool f = 1;
        ll alice = solve(0,j,1,piles,dp);
        ll total = accumulate(piles.begin(),piles.end(),0);
        return (alice<<1)>total;
    }
};