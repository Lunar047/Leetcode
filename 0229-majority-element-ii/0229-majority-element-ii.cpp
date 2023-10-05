class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> umap;
        set<int> st;
        int n = nums.size();
        for(int i=0;i<n;i++){
            umap[nums[i]]++;
            if(umap[nums[i]]>n/3 && st.find(nums[i])==st.end())
            {
                st.insert(nums[i]);
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }

};