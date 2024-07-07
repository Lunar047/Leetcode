class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int k = 1<<n;
        vector<vector<int>> powerSet(k);
        for(int i=0;i<(1<<n);i++){
            for(int j=0;j<n;j++){
                if(i &(1<<j)){
                    powerSet[i].push_back(nums[j]);
                }
            }
        }
        return powerSet;
    }
};