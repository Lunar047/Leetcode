class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for(auto &i:logs){
            if(i[0]=='.'){
                if(i[1]=='.')ans = max(0,ans-1);
            }
            else ans++;
        }
        return ans;
    }
};