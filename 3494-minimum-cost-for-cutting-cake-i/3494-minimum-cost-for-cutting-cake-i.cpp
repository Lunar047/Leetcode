class Solution {
private:
    typedef long long ll;
    int N,M;
    ll solve(int left,int right,int up,int down,vector<int>&h,vector<int>&v,vector<vector<vector<vector<ll>>>>&dp){
        if(left>=right && up >= down)return 0;
        // cout<<left<<" "<<right<<" "<<up<<" "<<down<<endl;
        if(dp[left][right][up][down]!=-1)return dp[left][right][up][down];
        ll ver = 1e9,hor = 1e9;
        if(left<right)
        for(int k = left;k<right;k++){
            ver = min(ver,v[k] + solve(left,k,up,down,h,v,dp) + solve(k+1,right,up,down,h,v,dp));
        }
        if(up<down)
        for(int k = up;k<down;k++){
            hor = min(hor,h[k] + solve(left,right,up,k,h,v,dp) + solve(left,right,k+1,down,h,v,dp));
        }
        return dp[left][right][up][down] = min(ver,hor);
    }
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
       M = m;
       N = n;
       vector<vector<vector<vector<ll>>>>dp(n+1,vector<vector<vector<ll>>>(n+1,vector<vector<ll>>(m+1,vector<ll>(m+1,-1))));
       return solve(0,n-1,0,m-1,horizontalCut,verticalCut,dp);
    }
};