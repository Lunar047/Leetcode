class Solution {
private:
    typedef long long int ll;
    int n;
    bool isPossible(vector<int> &start,int d,int mid){
        ll st = start[0];
        for(int i=1;i<n;i++){
            if(start[i] - st>=mid){
                st = start[i];
            }
            else if(st+mid>=start[i] && st+mid<=start[i]+d){
                st += mid;
                // continue;
            }
            else return 0;
        }
        return 1;
    }
public:
    int maxPossibleScore(vector<int>& start, int d) {
        n = start.size();
        sort(start.begin(),start.end());
        ll mx = d + start[n-1] - start[0],mn =0,mid;
        ll ans = 0;
        while(mn<=mx){
            mid = mn + (mx-mn)/2;
            // cout<<mid<<" ";
            if(isPossible(start,d,mid)){
                ans = mid;
                mn = mid+1;
            }
            else{
                mx = mid-1;
            }
        }

        return ans;
    }
};