class Solution {
private:
    int n;
    int solve(int ind,vector<int> &rating,vector<vector<vector<int>>> &dp,int size,bool f){
        if(ind>=n)return 0;
        if(size==2)return dp[ind][f][size] = 1;
        if(dp[ind][f][size]!=-1)return dp[ind][f][size];
        int ans = 0;
        if(f)
        for(int i = ind+1;i<n;i++){
            if(rating[i]>rating[ind]){
                ans+=solve(i,rating,dp,size+1,f);
            }
        }
        else
        for(int i = ind+1;i<n;i++){
            if(rating[i]<rating[ind]){
                ans+=solve(i,rating,dp,size+1,f);
            }
        }
        return dp[ind][f][size] = ans;
    }
public:
    int numTeams(vector<int>& rating) {
        n = rating.size();
        int ans = 0;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        for(int i=0;i<n;i++){
            ans+=solve(i,rating,dp,0,1);
            ans+=solve(i,rating,dp,0,0);
        }
        return ans;
    }
};