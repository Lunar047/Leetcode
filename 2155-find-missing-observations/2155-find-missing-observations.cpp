class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> ans(n,0);
        int m = rolls.size();
        int sum = accumulate(rolls.begin(),rolls.end(),0);
        int total = (n+m)*mean;
        int k = (total-sum)/n, k_l = (total-sum)%n;
        // cout<<k_l;
        // cout<<total-sum<<endl;
        for(int i=0;i<n;i++){
            ans[i] = k;
            if(k_l>0){
                ans[i]+=1;
                k_l--;
            }
            if(ans[i]>6 || ans[i]<1)return {};
        }
        return ans;
    }
};