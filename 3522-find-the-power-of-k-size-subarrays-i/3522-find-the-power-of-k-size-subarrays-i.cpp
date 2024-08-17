class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if(k==1){
            return nums;
        }
        vector<int> ans;
        int cnt = 1,n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1){
                cnt++;
            }
            else cnt--;
            if(i+1>=k){
                // cout<<cnt<<" ";
                if(cnt==k)ans.push_back(nums[i]);
                else ans.push_back(-1);
                if(nums[i-k+1]+1 == nums[i-k+2])cnt--;
                else cnt++;
            }
        }
        return ans;
    }
};