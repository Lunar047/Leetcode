class Solution {
private:
    vector<vector<int>> ans;
    int n;
    void solve(int target,int i,vector<int> &cur,vector<int>& candidates){
        if(target==0)ans.push_back(cur);
        if(target<=0)return;
        for(int index = i;index<n;index++){
            if(target>=candidates[index]){
                cur.push_back(candidates[index]);
                solve(target-candidates[index],index,cur,candidates);
                cur.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        vector<int> cur;
        solve(target,0,cur,candidates);
        return ans;
    }
};