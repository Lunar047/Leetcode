class Solution {
private:
    typedef long long int ll;
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        vector<int> ans;
        int n = queries.size();
        // priority_queue<ll,vector<ll>,greater<ll>> pq;
        priority_queue<ll> pq;
        for(auto &i:queries){
            ll d = abs(i[0]) + abs(i[1]);
            if(pq.size()<k){
                pq.push(d);
                if(pq.size()<k)ans.push_back(-1);
                else ans.push_back(pq.top());
            }
            else if(pq.size()>=k){
                if(pq.top()>d){
                    pq.pop();
                    pq.push(d);
                }
                ans.push_back(pq.top());
            }
        }
        return ans;
    }
};