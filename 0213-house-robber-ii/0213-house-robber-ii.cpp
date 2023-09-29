class Solution {
private:
    // int knapsack(int i,vector<int> &nums,bool f,vector<int> &dp){
    //     if(i>=nums.size())return 0;
    //     if(i == nums.size()-1 && f)return 0;
    //     if(dp[i]!=-1) return dp[i];
    //     int take = nums[i] +knapsack(i+2,nums,f,dp);
    //     int ntake = knapsack(i+1,nums,f,dp);
    //     return dp[i]=max(take,ntake);
    // }
public:
    int rob(vector<int>& nums) {
        int n =  nums.size();
        if(n==1)return nums[0];
        else if(n==2)return max(nums[0],nums[1]);
        vector<int> dp(n+1,-1);
        dp[0] = nums[0];
        for(int i=1;i<n-1;i++){
            int take = nums[i];
            if(i>1)take+=dp[i-2];
            int ntake = dp[i-1];
            dp[i] = max(take,ntake);
        }
        int zero = dp[n-2];
        fill(dp.begin(),dp.end(),-1);
        dp[0] = 0;
        for(int i=1;i<n;i++){
            int take = nums[i];
            if(i>1)take+=dp[i-2];
            int ntake = dp[i-1];
            dp[i] = max(take,ntake);
        }
        return max(zero,dp[n-1]);
    }
    // int rob(vector<int>& nums) {
        // vector<int> dp(nums.size()+1,-1);
        // if(nums.size()<3){
        //     int z = knapsack(0,nums,0,dp);
        //     return z;
        // }
        // else{
        // int first = nums[0] + knapsack(2,nums,1,dp);
        // fill(dp.begin(),dp.end(),-1);
        // int second = nums[1] + knapsack(3,nums,0,dp);
        // int k = *max_element(nums.begin(),nums.end());
        // return max({k,first,second});
        // }
    // }
};