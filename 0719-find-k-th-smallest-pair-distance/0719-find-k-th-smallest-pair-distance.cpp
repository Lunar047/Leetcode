class Solution {
private:
    int n,ans = -1;
    int count(int mid,vector<int>&nums,int &mx_dif){
        int cnt = 0;
        mx_dif = -1;
        for(int i=0;i<n-1;i++){
            int lb = upper_bound(nums.begin(),nums.end(),nums[i]+mid)-nums.begin();
            // cout<<nums[i]<<" "<<lb<<" "<<(lb-i-1)<<"  ";
            mx_dif = max(mx_dif,nums[lb-1] - nums[i]);
            cnt += (lb-i-1);
        }
        // cout<<mid<<" : "<<cnt<<endl;
        // ans = mx_dif;
        return cnt;
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        n = nums.size();
        sort(nums.begin(),nums.end());
        int low = 0,high = nums[n-1] - nums[0],mid,mx_dif;
        while(low<=high){
            mid = (high+low)/2;
            int d = count(mid,nums,mx_dif);
            // cout<<mid<<" "<<d<<" "<<mx_dif<<endl;
            if(d>=k){
                ans = mx_dif;
                high = mid -1;
            }
            else low = mid +1;
            // else high = mid - 1;
        }
        return ans;
    }
};