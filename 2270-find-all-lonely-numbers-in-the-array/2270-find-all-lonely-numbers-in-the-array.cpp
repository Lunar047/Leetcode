class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> mp;
        for(auto &i:nums){
            mp[i]++;
        }
        for(auto &i:nums){
            if(mp.count(i+1) || mp.count(i-1) || mp[i]>1)continue;
            else ans.push_back(i);
        }
        return ans;
    }
};