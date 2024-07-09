class Solution {
private:
    int n;
    typedef int ll;
    int lowerBound(vector<ll> &a,ll target){ ll s =0,e = a.size()-1,m = s+(e-s)/2; while(s<=e){ if(a[m]<target) s = m +1; else e = m-1; m = s+(e-s)/2;}return s;}
public:
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        vector<int> lis;
        lis.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]>lis.back()){
                lis.push_back(nums[i]);
            }
            else{
                int index = lowerBound(lis,nums[i]);
                lis[index] = nums[i];
            }
        }
        return lis.size();
    }
};