class Solution {
private:
    int mod = 1e9+7;
    int sumn(long long n){
        return (n*(n+1)/2)%mod;
    }
public:
    int countHomogenous(string s) {
        if(s.size()==1)return 1;
        else if(s.size()==0)return 0;
        int ans = 0;
        int left =1,count =1;
        char c= s[0];
        while(left<s.size()){
            if(s[left]!=c){
               ans +=sumn(count);
                count =0;
                c = s[left];
                ans%=mod;
            }
            left++;
            count++;
        }
        ans +=sumn(count);
        return ans;
    }
};