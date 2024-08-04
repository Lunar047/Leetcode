class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        int k = queries.size();
        vector<int> dist(n,0),ans;
        set<int> st;
        for(int i=0;i<n;i++){
           st.insert(i);
        }
        for(int i=0;i<k;i++){
            int u = queries[i][0],v = queries[i][1];
            st.erase(st.upper_bound(u),st.lower_bound(v));
            ans.push_back(st.size()-1);
        }
        return ans;
    }
};