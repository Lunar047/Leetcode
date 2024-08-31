class Solution {
private:
    typedef long long int ll;
    typedef pair<ll,ll> pll;
    struct compare{
        bool operator()(pll &below, pll &above)
        {
            return below.first*above.second < above.first*below.second;
        }
    };
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        int n = damage.size();
        for(auto &i:health){
            i = i/power + (i%power != 0);
        }
        ll sum = accumulate(damage.begin(),damage.end(),0),ans = 0;
        priority_queue<pll,vector<pll>,compare> pq;
        for(int i=0;i<n;i++){
            pq.push({damage[i],health[i]});
        }
        while(!pq.empty()){
            auto [d,t] = pq.top();
            ans += (sum*t);
            sum-=d;
            pq.pop();
        }
        return ans;
    }
};