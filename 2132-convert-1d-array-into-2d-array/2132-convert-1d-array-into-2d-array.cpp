class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int s  = original.size();
        if(s!=(n*m))return {};
        vector<vector<int>> ans;
        vector<int> temp;
        int cnt = 0;
        for(auto &i:original){
            temp.push_back(i);
            cnt++;
            if(cnt%n==0){
                cnt = 0;
                ans.push_back(temp);
                temp.clear();
            }
        }
        return ans;
    }
};