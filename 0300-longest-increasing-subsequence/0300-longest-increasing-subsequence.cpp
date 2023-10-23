class Solution {
public:
    int solve(int index,int prev,vector<int> &nums,vector<vector<int>> &dp){
        if(index==nums.size()){
            return 0;
        }
        if(dp[index][prev+1]!=-1)return dp[index][prev+1];
        int ntake = solve(index+1,prev,nums,dp);
        int take =0;
        if(prev==-1 || nums[index]>nums[prev]){
        take = 1+solve(index+1,index,nums,dp);
        }
        // return max(ntake,take);
        return dp[index][prev+1] = max(take,ntake);

    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
         vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
         return solve(0,-1,nums,dp);
    //    for(int i=0;i<n;i++){
    //        int t = nums[i];
    //        for(int j=0;j<n;j++){
    //            if(nums[j]>t){
    //                dp[i+1][j+1] = 1+ dp[i][j];
    //                t = nums[j];
    //            }
    //            else
    //            {
    //                dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
    //            }
    //        }
    //    }
    //    return dp[n][n];

    }
};