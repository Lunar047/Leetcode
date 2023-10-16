class Solution {
public:
    int numSteps(string s) {
        reverse(s.begin(),s.end());
        int n= s.size();
        int ans = 0;
        int i=0;
        while(i<n){
            // cout<<s<<" ";
            if(s[i]=='0'){
                ans++;
                i++;
            }
            else{
                if(i==n-1)break;
                ans++;
                s[i] -= 1;
                int k = 1,j = i+1;
                while(j<s.size()){
                    if(s[j]=='0'){
                        s[j]+=1;
                        k=0;
                        break;
                    }
                    else{
                        s[j]-=1;
                    }
                    j++;
                }
                if(k)s.push_back('1');
            }
        }
        // if(s[s.size()-1]=='0')ans++;
        return ans;
    }
};