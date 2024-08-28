class Solution {
private:
    long long mod = 1e9+7;
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        // sort(nums.begin(),nums.end());
        vector<long long> subSum;
        long long ans = 0,idx=1;
        for(int i=0;i<n;i++){
            long long sum = 0;
            for(int j=i;j<n;j++){
                sum+= nums[j];
                subSum.push_back(sum);
            }
        }
        sort(subSum.begin(),subSum.end());
        // for(auto &i:subSum)cout<<i<<" ";cout<<endl;
        for(int i = left-1;i<right;i++){
            ans+=subSum[i];
            ans%=mod;
        }
        return ans;
    }
};