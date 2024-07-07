class Solution {
private:
    vector<vector<string>> ans;
    bool palindrome(int i,int j,string &s){
        while(i<j){
            if(s[i++]^s[j--])return 0;
        }
        return 1;
    }
    void solve(int left,int right,string &s,vector<string>&cur){
        if(left>=right){
             ans.push_back(cur);
            return;
        }
        for(int k = left;k<right;k++){
            if(palindrome(left,k,s)){
                cur.push_back(s.substr(left,k-left+1));
                solve(k+1,right,s,cur);
                cur.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> cur;
        solve(0,s.size(),s,cur);
        return ans;
    }
};