class Solution {
private:
    void solve(int i,int close,vector<string> &ans,string cur){
        if(!i && !close){
            ans.push_back(cur);
            return;
        }
        if(i>0){
            cur.push_back('(');
            solve(i-1,close,ans,cur);
            cur.pop_back();
        }
        if(close>i){
            cur.push_back(')');
            solve(i,close-1,ans,cur);
            cur.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur;
        solve(n,n,ans,cur);
        return ans;
    }
};