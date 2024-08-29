class Solution {
private:
    typedef long long ll;
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size(),m = points[0].size();
        vector<ll> pre(m,0),suf(m,0),ans(m,0);
        for(int i=0;i<m;i++){
            ans[i] = points[0][i];
            pre[i] = max(ans[i],i>0?pre[i-1]-1:(ll)0);
            suf[m-i-1] = max((ll)points[0][m-i-1],(i>0)?(ll)suf[m-i]-1:(ll)0);
        }
        for(int i=1;i<n;i++){
            // for(auto &i:pre)cout<<i<<" ";cout<<endl;
            // for(auto &i:suf)cout<<i<<" ";cout<<endl;
           for(int j=0;j<m;j++){
            ans[j] = points[i][j] + max(pre[j],suf[j]);
           }
           for(int j=0;j<m;j++){
                pre[j] = max(ans[j],j>0?pre[j-1]-1:(ll)0);
                suf[m-j-1] = max((ll)ans[m-j-1],(j>0)?(ll)suf[m-j]-1:(ll)0);
           }
        }
        return *max_element(ans.begin(),ans.end());
    }
};