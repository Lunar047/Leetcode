class Solution {
private:
    typedef long long ll;
    int n;
    vector<ll> a,b;

    void solve(int i,vector<int>&ea,vector<int>&eb){
        if(i>=n)return;
        a[i] = ea[i] + max(a[i-1],i>1?b[i-2]:0);
        b[i] = eb[i] + max(b[i-1],i>1?a[i-2]:0);
        solve(i+1,ea,eb);
    }
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        n = energyDrinkA.size();
        a.resize(n,0);
        b.resize(n,0);
        a[0] = energyDrinkA[0];
        b[0] = energyDrinkB[0];
        solve(1,energyDrinkA,energyDrinkB);
        // for(auto &i:a)cout<<i<<" ";
        return max(a[n-1],b[n-1]);
    }
};