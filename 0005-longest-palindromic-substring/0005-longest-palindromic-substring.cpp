class Solution {
public:
    string solve(int i,string &s)
    {
        string pre="",f="";
        string pre2="",f2="";
        f+=s[i];
        int k = i-1,j=i+1;
        if(i<s.size()&&(s[i]==s[i+1]))
        {
              f2+=s[i];
              f2+=s[i];
             int k2 = i-1,j2=i+2;
              while(k2>=0 && j2<s.size())
             { 
            if(s[k2]!=s[j2])
            {
                break;
            }
            else
            {
                pre2+=s[k2--];
                f2+=s[j2++];
            }
             }
        }
    
        while(k>=0 && j<s.size())
        { 
            if(s[k]!=s[j])
            {
                break;
            }
            else
            {
                pre+=s[k--];
                f+=s[j++];
            }
        }

        reverse(pre.begin(),pre.end());
        reverse(pre2.begin(),pre2.end());
        string ans1 = pre+f,ans2 = pre2+f2;
        // cout<<"inside solve  "<<ans1<<"  "<<ans2<<endl;
        if(ans1.size()>ans2.size())  return ans1;
        else return ans2;
        // return pre+f;
    }
    string longestPalindrome(string s) {
        // 2nd attempt
        string ans="";
        for(int i=0;i<s.size();i++)
        {
           string t = solve(i,s);
           if(t.size()>=ans.size())
            ans = t;
        }
        return ans;
    }
};



































