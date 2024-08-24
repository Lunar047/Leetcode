class Solution {
private:
    typedef long long int ll;
    ll ans = LLONG_MIN;
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        ll n = board.size(),m = board[0].size();
        vector<vector<ll>> temp,arr;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                temp.push_back({board[i][j],i,j});
        // sort(temp.begin(),temp.end(),[this](vector<ll>&a,vector<ll>&b){return a[0]>b[0];});
        sort(temp.rbegin(),temp.rend());
        // for(auto &i:temp){
        //     cout<<i[0]<<" ";
        // }
        vector<int> cnt(n,0);
        ll t = temp.size();
        int total = 0;
        for(int i=0;i<t;i++){
            if(cnt[temp[i][1]]<5){
                total++;
                cnt[temp[i][1]]++;
                arr.push_back(temp[i]);
            }
            else if(total>=(n*6))break;
        }
        t = arr.size();
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
        // vector<vector<pair<int,int>>> temp(n);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         temp[i].push_back({board[i][j],j});
        //         }
        // }
        // for(int i=0;i<n;i++){
        //     sort(temp[i].begin(),temp[i].end(),[this](pair<int,int> &a,pair<int,int>&b){
        //     return a.first>b.first;
        //     });
        // }
        // vector<vector<int>> temp2;
        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<3;j++)
        //         temp2.push_back({temp[i][j].first,i,temp[i][j].second});
        //         // cout<<j.first<<" "<<j.second<<" ";cout<<endl;
            
        // }
        // sort(temp2.begin(),temp2.end(),[this](vector<int>&a,vector<int>&b){
        //     return a[0]>b[0];
        // });
        // ll bound = temp2[0][0]+temp2[1][0]+temp2[2][0];
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         ll cur = board[i][j];
        //         for(int k=0;k<n;k++)
        //             for(int l=0;l<m;l++){
        //                 if(k==i || l ==j)continue;
        //                 int l1 = 0;
        //                 // ll target = cur+board[k][l]
        //                 while(1){
        //                     if(temp2[l1][1] ==i || temp2[l1][1] ==k || temp2[l1][2] ==j || temp2[l1][2] ==l)l1++;
        //                     else{
        //                         break;
        //                     }
        //                 }
        //                 ans = max(ans,cur + (ll)board[k][l] +(ll) temp2[l1][0]);
        //             }
        //     }
        // }
        
        return ans;
    }
};