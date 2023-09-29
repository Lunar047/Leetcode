class Solution {
private:
   
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // Optimized
        int prev  = nums[0],prev2 = 0;
        for(int i=1;i<n;i++){
            int take = nums[i]+prev2;
            prev2 = prev;
            prev = max(take,prev);
        }
        return prev;
    }
};