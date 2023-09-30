class Solution {
public:
    void solve(int t,int sum,vector<int> can,int i,vector<int> o,vector<vector<int>> &ans)
    {
        if(sum>=t || i>=can.size())
        {
            if(sum==t)
            ans.push_back(o);
            return ;
        }
       
        sum+=can[i];
        o.push_back(can[i]);
        solve(t,sum,can,i,o,ans);
        o.pop_back();
        sum-=can[i];
        solve(t,sum,can,i+1,o,ans);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int i =0;
        vector<vector<int>> ans;
        vector<int> o;
        int sum =0;
        solve(target,sum,candidates,i,o,ans);
        return ans;
    }
};