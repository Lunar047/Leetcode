class Solution {
public:
    void solve(vector<int> nums,int in,vector<vector<int>> &ans)
    {
      if(in>=nums.size())
      {  
          ans.push_back(nums);
          return ;
      }
      for(int i=in;i<nums.size();i++)
      {
          swap(nums[in],nums[i]);
        //   o.push_back(nums[i]);
          solve(nums,in+1,ans);
          swap(nums[i],nums[in]);
        //   o.pop_back();

      }

    }
    vector<vector<int>> permute(vector<int>& nums) {
     vector<vector<int>> ans;
     int i = 0;
     solve(nums,i,ans);
     return ans;
    }
};