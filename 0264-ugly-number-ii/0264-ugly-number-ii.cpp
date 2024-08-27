bool f = 1;
vector<int> ugly(2,-1);
vector<int> ans;
typedef long long ll;
bool check(ll n){
    ll i = 2;
    while(i*i<=n){
        if(n%i==0){
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
void temp(){
    f = 0;
    ugly[1] = ugly[2] = ugly[3] = ugly[4] = ugly[5] = 1;
    for(ll i = 2;i<2e5;i++){
        if(ugly[i] ==1 || check(i)){
            ugly[i] = 1;
            ll nxt = (i<<1);
            while(nxt<2e5){
                ugly[nxt] = 1;
                nxt<<=1;
            }
            nxt = i*3;
            while(nxt<2e5){
                ugly[nxt] = 1;
                nxt*=3;
            }
            nxt = i*5;
            while(nxt<2e5){
                ugly[nxt] = 1;
                nxt*=5;
            }
        }
        else{
            ll k = i,j=2;
            while(k<2e5){
                ugly[k] = 0;
                k*=j;
                j++;
            }

        }
    }
    for(int i=1;i<2e5;i++){
        if(ugly[i]){
            ans.push_back(i);
        }
    }
}
void generate(){
    f = 0;
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    pq.push((ll)1);
    map<ll,bool> mp;
    mp[1] = 1;
    int cnt = 1;
    vector<ll> e = {2,3,5};
    while(cnt<1799){
        ll node = pq.top();
        pq.pop();
        for(auto &i:e){
            ll nxt = i*node;
            if(mp.count(nxt))continue;
            mp[nxt] = 1;
            pq.push(nxt);
            cnt++;
        }
    }
    for(auto &i:mp){
        ans.push_back(i.first);
    }
}
class Solution {
private:

public:
    int nthUglyNumber(int n) {
        // if(f){
        //     // temp();
        // }
        // cout<<ans.size()<<endl;
        // for(auto &i:ans)cout<<i<<" ";cout<<endl;
        // int k = ans.size();
        // for(k;k>0;k--)cout<<ans[k-1]<<" ";
        // return ans[n-1];
        
        // Approach 02
        if(f){
            generate();
        }
        return ans[n-1];
    }
};