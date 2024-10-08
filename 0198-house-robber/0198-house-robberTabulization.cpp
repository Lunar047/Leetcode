class Solution {
private:
   
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        dp[0] = nums[0];
        // Tabulization
        for(int i=1;i<n;i++){
            int take = nums[i];
            if(i>1)take+=dp[i-2];
            int ntake = dp[i-1];
            dp[i] = max(take,ntake);
        }
        return dp[n-1];
    }
};
