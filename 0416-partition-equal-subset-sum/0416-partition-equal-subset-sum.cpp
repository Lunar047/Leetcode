class Solution {
private:
    bool targetSum(int idx,int target,vector<int>&nums,vector<vector<int>> &dp){
        if(target==0)return 1;
        else if(target<0 || idx>=nums.size())return 0;
        if(dp[idx][target]!=-1)return dp[idx][target];
        return dp[idx][target] = (targetSum(idx+1,target-nums[idx],nums,dp) || targetSum(idx+1,target,nums,dp));
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        long long sum = accumulate(nums.begin(),nums.end(),0);
        if(sum&1)return 0;
        sum/=2;
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        return targetSum(0,sum,nums,dp);
    }
};