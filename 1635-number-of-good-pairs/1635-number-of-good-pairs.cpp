class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> up;
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            if(up.count(nums[i]))ans+=up[nums[i]];
            up[nums[i]]++;
        }
        return ans;
    }
};