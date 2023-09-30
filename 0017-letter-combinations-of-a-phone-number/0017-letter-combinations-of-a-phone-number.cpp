class Solution {
public:
    string s[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void solve(vector<string> & ans,string c,int in,string &dig){
        if(in>=dig.size()){
            ans.push_back(c);
            return;
        }
        int t = dig[in]-'0';
        for(int i=0;i<s[t].size();i++){
            c.push_back(s[t][i]);
            solve(ans,c,in+1,dig);
            c.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()<1)return ans;
        string c;
        int i =0;
        solve(ans,c,i,digits);
        return ans;
    }
    // void solve(string d,string o,int i,vector<string> &ans)
    // {
    //    if(i>=d.size())
    //    {
    //        ans.push_back(o);
    //        return ;
    //    }
    //    int j = 0,in=d[i]-'0';
    //    string s2 = s[in];
    //    while(j<s2.length())
    //    {
    //        o.push_back(s2[j]);
    //        solve(d,o,i+1,ans);
    //        o.pop_back();
    //        j++;
    //    }

    // }
    // vector<string> letterCombinations(string digits) {
    //  vector<string> ans;
    //  string o;
    //  int i=0;
    //  if(digits.size()<1)
    //  return ans;
    //  solve(digits,o,i,ans);
    //  return ans;
    // }
};