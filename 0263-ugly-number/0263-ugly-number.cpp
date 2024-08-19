class Solution {
private:
    typedef long long ll;
    vector<ll> factors(ll n){
        vector<ll> fac;
        ll i = 2;
        for(i;i*i<=n;i++){
            if(n%i==0){
                fac.push_back(i);
                // if(n/i != i)fac.push_back(n/i);
                while(n%i==0)n/=i;
            }
        }
        if(n>1)fac.push_back(n);
        return fac;
    }
public:
    bool isUgly(int n) {
        if(n<=0)return 0;
        vector<ll> f = factors(n);
        for(auto &i:f){
            // cout<<i<<" ";
            if(i==2 || i==3 || i==5)continue;
            else return 0;
        }
        return 1;
    }
};