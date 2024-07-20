class Solution {
private:
    int solve(vector<int> &nums,vector<int> &diff,int dif,int k,int n){
         int ans = 0;
        for(int i=0;i<n/2;i++){
            if(diff[i]==dif)continue;
            int temp = abs(diff[i] - dif);
            if(diff[i]<dif){
                if(min(nums[i],nums[n-i-1])-temp>=0 || max(nums[i],nums[n-i-1])+temp<=k)ans++;
                else ans+=2;
            }
            else{
                if(min(nums[i],nums[n-i-1])+temp<=k || max(nums[i],nums[n-i-1])-temp>=0)ans++;
                else ans+=2;
            }
            // cout<<i<<" "<<ans<<endl;
        }
        return ans;
    }
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> diff(n/2,0);
        map<int,int> mp;
        for(int i=0;i<n/2;i++){
            diff[i] = abs(nums[i] - nums[n-i-1]);
            mp[diff[i]]++;
        }
        // vector<int> d2 = diff;
        // sort(d2.begin(),d2.end());
        // int dif = mp[d2[n/4]]>mp[d2[n/4-1]]?d2[n/4]:d2[n/4-1],cnt = 0;
        int ans = 1e9;
        int dif1 = k,cnt = 0,dif2 = dif1;
        for(auto &i:mp){
            // if(i.first<=k)
            if(i.first<=k && i.second>cnt){
                cnt = i.second;
                ans = min(ans,solve(nums,diff,i.first,k,n));
            }
        }
        // cout<<dif<<" ";
       

        return ans;
    }
};