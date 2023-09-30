class Solution {
public:
    // bool isValid(string s)
    // {
    //     stack<char> p;
    //     for(int i=0;i<s.size();i++)
    //     {
    //         if(s[i]=='(')
    //         p.push(s[i]);
    //         else
    //         {
    //             if(p.top()=='(')
    //             {
    //                 p.pop();
    //             }
    //             else return false;
    //         }
           
    //     }
    //      if(p.size()<1) return true;
    //         else return false;
    // }
    // void solve(vector<string> &ans,string t,string c,int j)
    // {
    //  if(j>c.size())
    //  {
    //    if(c.size()==6 && isValid(c)) ans.push_back(c);
    //    return ;
    //  }
    //  for(int i=0;i<t.size();i++)
    //  {
    //      solve(ans,t,c,j+1);
    //      c+=t[i];
    //      solve(ans,t,c,j+1);
    //      c.pop_back();
    //  }
    // }
    //Method 2
    // bool isValid(string s)
    // {
    //     stack<char> t;
    //     for(int i =0;i<s.size();i++)
    //     {
    //         if(s[i]=='(')
    //         t.push(s[i]);
    //         else if(s[i]==')' && t.size()>0)
    //         {
    //            t.pop();
    //         }
    //         else return false;
    //     }
    //     if(t.size()<1)return true;
    //     else return false;
    // }
    void solve( vector<string> & ans,int o,int c,int& n,string output){
        if(o>n || c>n) return;
        if(o==n && c ==n)
        {
            ans.push_back(output);
            output.clear();
            return ;
        }
        if(o>c)
        {
            output.push_back(')');
            solve(ans,o,c+1,n,output);
            output.pop_back();
        }
        if(o<n)
        {
            output.push_back('(');
            // c--;
            solve(ans,o+1,c,n,output);
            output.pop_back();
        }
        
       
    }
   vector<string> generateParenthesis(int n) {
       string output = "";
       vector<string> ans;
       int o = 0,c = 0;
       solve(ans,o,c,n,output);
       return ans;
   }
    
    // vector<string> generateParenthesis(int n) {
    //  string t = "";
    //  for(int i=0;i<n;i++)
    //   t+="()";
    //  vector<string> ans;
    //  string c;
    //  solve(ans,t,c,0);
    //  return ans;
    // }
};