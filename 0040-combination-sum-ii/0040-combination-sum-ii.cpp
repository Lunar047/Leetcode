class Solution {
private:
    vector<vector<int>> ans;
    // set<vector<int>> st;
    int n;
    // void solve(int i,vector<int>& candidates, int &target,vector<int>&cur,int sum){
    //     if(i>=n){
    //         if(sum==0){
    //             // vector<int> t = cur;
    //             // sort(t.begin(),t.end());
    //             st.insert(cur);
    //             // ans.push_back(cur);
    //         }
    //         return;
    //     }
    //     solve(i+1,candidates,target,cur,sum);
    //     if(candidates[i]<=sum){
    //     cur.push_back(candidates[i]);
    //     solve(i+1,candidates,target,cur,sum-candidates[i]);
    //     cur.pop_back();
    //     }
    // }
    void solve(int i,vector<int>& candidates, int target,vector<int>&cur){
        if(target==0){
                ans.push_back(cur);
                return;
        }
        if(i>=n || candidates[i]>target)return;
        for(int id = i;id<candidates.size();id++){
            if(id^i && !(candidates[id]^candidates[id-1])){
                continue;
            }
            else
            {
                // m[candidates[id]]++;
                cur.push_back(candidates[id]);
                solve(id+1,candidates,target-candidates[id],cur);
                cur.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       vector<int> cur;
       n = candidates.size();
       sort(candidates.begin(),candidates.end());
    //    solve(0,candidates,target,cur,target);
        solve(0,candidates,target,cur);
    //    return {st.begin(),st.end()};
        return ans;
    }
};