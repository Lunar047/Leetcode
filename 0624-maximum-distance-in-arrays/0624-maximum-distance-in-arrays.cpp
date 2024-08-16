class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mn = 0,mx = 0,n = arrays.size(),ans = 0;
        for(int i=0;i<n;i++){
            if(!i){
                mn = arrays[i][0];
                mx = arrays[i][arrays[i].size()-1];
            }
            else{
                // cout<<(mx-arrays[i][0])<<" "<<mn<<endl;
                ans = max({ans,abs(mx - arrays[i][0]),abs(arrays[i][arrays[i].size()-1]-mn)});
                mn = min(arrays[i][0],mn);
                mx = max(arrays[i][arrays[i].size()-1],mx);
            }
        }
        return ans;
    }
};