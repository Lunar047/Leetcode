class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size(),mx = 0,ans = 0,cnt = 0;
        int total = accumulate(nums.begin(),nums.end(),0);
        if(total==n)return 0;
        for(int i=0;i<2*n-1;i++){
            cnt+=nums[i%n];
            if(i>=total)cnt-=nums[(i-total+n)%n];
            mx = max(mx,cnt);
        }
        return total-mx;
    }

};