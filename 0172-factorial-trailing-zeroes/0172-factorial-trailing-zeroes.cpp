class Solution {
public:
    int trailingZeroes(int n) {
       int ans = 0;
       while(n && n%5!=0)n--;
       while(n){
           int t = n;
           while(t%5==0){
               ans++;
               t/=5;
           }
           n-=5;
       }
        return ans;
    }
};