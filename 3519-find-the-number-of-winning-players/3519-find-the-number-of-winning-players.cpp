class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<map<int,int>> cnt(n+1);
        for(auto &i:pick){
            cnt[i[0]][i[1]]++;
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(auto &it:cnt[i]){
                if(it.second>i){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};