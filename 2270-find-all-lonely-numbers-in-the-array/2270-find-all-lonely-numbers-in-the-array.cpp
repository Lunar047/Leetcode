class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        for(size_t i = 0;i<nums.size();i++){
            if((i && nums[i]-nums[i-1]<=1) || (i<nums.size()-1 && nums[i+1]-nums[i]<=1))continue;
            else ans.push_back(nums[i]);
        }
        return ans;
       
    }
};