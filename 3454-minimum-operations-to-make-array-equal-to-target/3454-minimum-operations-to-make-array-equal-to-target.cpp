class Solution {
private:
    typedef long long ll;
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        vector<int> diff(n,0);
        for(int i=0;i<n;i++){
            diff[i] = target[i]-nums[i];
        }
        ll ans = 0,prev=0,prev2=0;
        for(int i=0;i<n;i++){
            if(diff[i]>=0){
                prev2 = 0;
                if(diff[i]-prev>0)ans+=(diff[i]-prev);
                prev = diff[i];
            }
            else{
                prev = 0;
                if(prev2-diff[i]>0)ans+=(prev2-diff[i]);
                prev2 = diff[i];
            }
        }
        return ans;
    }
};