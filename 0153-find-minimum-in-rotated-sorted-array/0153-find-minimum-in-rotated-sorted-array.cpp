class Solution {
public:
    int pivot(vector<int>& nums)
    {
        int s=0,e=nums.size()-1,m = s+(e-s)/2;
        while(s<e)
        {
            if(nums[m]>=nums[0])
            s = m+1;
            else 
            e = m;
            m = s+(e-s)/2;
        }
        return s;
    }
    int findMin(vector<int>& nums) {
    //    int k =0;
    //    if(nums.size()==1) return nums[0]; 
    //    for(int i=0;i<nums.size();i++)
    //    {
    //        if(i+1==nums.size()||nums[i+1]<nums[i])
    //        k=i;
    //    }
    //    if(k==0 || k == nums.size()) return nums[0];
    //    return nums[k];
     int p = pivot(nums),n = nums.size()-1;
    //  cout<<p<<endl;
    if(p == n && (p==0 || nums[p-1]<nums[p])) return nums[0];
    else return nums[p];
    }
};
/*
if(k==0|| k == nums.size()-1) return i;
            else
            return (k+i)%(nums.size()-1);
*/