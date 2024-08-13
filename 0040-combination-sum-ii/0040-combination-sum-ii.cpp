class Solution {
private:
    int n;
    vector<vector<int>> ans;
    void solve(int idx,int target,vector<int>&candidates,vector<int>&cur){
        if(!target){
            ans.push_back(cur);
            return;
        }
        if(target<0 || idx>=n)return;
        for(int i= idx;i<n;i++){
            if(idx^i && !(candidates[i]^candidates[i-1]))continue;
            cur.push_back(candidates[i]);
            solve(i+1,target-candidates[i],candidates,cur);
            cur.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n = candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<int> cur;
        solve(0,target,candidates,cur);
        return ans;
    }
};