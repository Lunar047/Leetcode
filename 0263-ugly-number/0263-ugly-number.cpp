class Solution {
private:
    typedef long long ll;
    bool check(ll n){
        ll i = 2;
        while(i*i<=n){
            if(n%i==0){
                // cout<<i<<" ";
                if(i==2 || i==3 || i==5){
                    while(n%i==0)n/=i;
                }
                else return 0;
            }
            i++;
        }

        if(n>1 && !(n==2 || n==3 || n==5))return 0;
        else return 1;
    }
public:
    bool isUgly(int n) {
        if(n<=0)return 0;
        return check(n);
    }
};