class Solution {
  private:
    void solve(int i,vector<string>&ans,string &a,vector<string>&phone,string &cur,int &N){
        if(i>=N){
            if(cur.size())ans.push_back(cur);
            return;
        }
        // cout<<a[i]-'0'<<" ";
        for(int j=0;j<phone[a[i]-'0'].size();j++){
            cur.push_back(phone[a[i]-'0'][j]);
            solve(i+1,ans,a,phone,cur,N);
            cur.pop_back();
        }
        
    }
public:
    vector<string> letterCombinations(string digits) {
         vector<string> ans;
        vector<string> phone = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string cur;
        int n = digits.size();
        solve(0,ans,digits,phone,cur,n);
        return ans;
    }
};