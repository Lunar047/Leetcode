class Solution {
private:
    typedef long long int ll;
    typedef pair<ll,ll> pll;
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        priority_queue<ll> pq1,pq2;
        ll part1 = 1,part2 = 1;
        for(int i=0;i<m-1;i++)pq1.push(horizontalCut[i]);
        for(int i=0;i<n-1;i++)pq2.push(verticalCut[i]);
        ll ans = 0;
        while(!pq1.empty() && !pq2.empty()){
            if(pq1.top()>pq2.top()){
                ans += (part2*pq1.top());
                pq1.pop();
                part1++;
            }
            else {
                ans += (part1*pq2.top());
                pq2.pop();
                part2++;
            }
        }
        while(!pq1.empty()){
            ans += (part2*pq1.top());
                pq1.pop();
                part1++;
            
        }
        while(!pq2.empty()){
             ans += (part1*pq2.top());
                pq2.pop();
                part2++;
        }
        return ans;
    }
};