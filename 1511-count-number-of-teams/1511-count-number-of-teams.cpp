class Solution {
private:
    int n;
    int solve(int ind,vector<int> &rating,vector<vector<int>> &dp,int size){
        if(ind>=n)return 0;
        if(size==2)return dp[ind][size] = 1;
        if(dp[ind][size]!=-1)return dp[ind][size];
        int ans = 0;
        for(int i = ind+1;i<n;i++){
            if(rating[i]>rating[ind]){
                ans+=solve(i,rating,dp,size+1);
            }
        }
        return dp[ind][size] = ans;
    }
    int solve2(int ind,vector<int> &rating,vector<vector<int>> &dp,int size){
        if(ind>=n)return 0;
        if(size==2)return   dp[ind][size] = 1;
        if(dp[ind][size]!=-1)return dp[ind][size];
        int ans = 0;
        for(int i = ind+1;i<n;i++){
            if(rating[i]<rating[ind]){
                ans+=solve2(i,rating,dp,size+1);
            }
        }
        return dp[ind][size] = ans;
    }
public:
    int numTeams(vector<int>& rating) {
        n = rating.size();
        int ans = 0;
        vector<vector<int>> dp(n,vector<int>(3,-1)),dp2 = dp;
        for(int i=0;i<n;i++){
            ans+=solve(i,rating,dp,0);
            ans+=solve2(i,rating,dp2,0);
        }
        return ans;
    }
};