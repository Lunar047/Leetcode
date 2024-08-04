class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int ans = 0;
        for(int i=1;i<n-1;i++){
            int l1 =0,r1=0,l2=0,r2=0;
            for(int j=0;j<i;j++)if(rating[j]<rating[i])l1++;else if(rating[j]>rating[i])l2++;
            for(int k=i+1;k<n;k++)if(rating[k]>rating[i])r1++;else if(rating[k]<rating[i])r2++;
            ans+=(l1*r1 + l2*r2);
        }
        return ans;
    }
};