class Solution {
private:
    typedef long long ll;
    ll ans = LLONG_MIN;
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        ll n = board.size(),m = board[0].size();
        vector<vector<ll>> arr;
        vector<vector<pair<int,int>>> temp(n);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                temp[i].push_back({board[i][j],j});
        // sort(temp.begin(),temp.end(),[this](vector<ll>&a,vector<ll>&b){return a[0]>b[0];});
        for(int i=0;i<n;i++)
            sort(temp[i].rbegin(),temp[i].rend());
        // for(int i=0;i<n;i++)
        // for(auto &j:temp[i]){
        //     cout<<j.first<<" ";
        // }
        // vector<int> cnt(n,0);
        // ll t = temp.size();
        int total = 0;
        for(int i=0;i<n;i++){
           for(int j=0;j<min((ll)5,m);j++){
                // cout<<i<<" "<<j<<" ";
                arr.push_back({temp[i][j].first,i,temp[i][j].second});
           }
            //   cout<<endl;
        }
        sort(arr.rbegin(),arr.rend());
        ll t = arr.size();
        for(int i=0;i<t-2;i++){
            for(int j=i+1;j<t-1;j++){
                if(arr[i][1]==arr[j][1] ||  arr[i][2] == arr[j][2])continue;
                for(int k = j+1;k<t;k++){
                    if(arr[k][1]==arr[i][1] || arr[k][1] ==arr[j][1] || arr[k][2]==arr[i][2] || arr[k][2]==arr[j][2])continue;
                    else{
                        // if(arr[i][0] + arr[j][0]+arr[k][0]>ans)cout<<arr[i][1]<<" "<<arr[i][2]<<" "<<arr[j][1]<<" "<<arr[j][2]<<" "<<arr[k][1]<<" "<<arr[k][2]<<":"<<ans<<endl;
                        ans = max(ans,arr[i][0] + arr[j][0]+arr[k][0]);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};