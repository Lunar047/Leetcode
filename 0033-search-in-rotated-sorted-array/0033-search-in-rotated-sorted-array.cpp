class Solution {
public:
    int pivot(vector<int> & nums)
    {
        int s =0,e = nums.size()-1,m = s+(e-s)/2;
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
    int BinarySearch(vector<int> & nums,int s,int e,int & target)
    {
        // for(int i = s;i<=e;i++)
        // cout<<nums[i]<<"  ";
        int m = s+(e-s)/2;
        while(s<=e)
        {
            if(nums[m]==target) return m;
            else if(nums[m]>target) e = m-1;
            else s = m+1;
            m = s+(e-s)/2;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        // int k =0;
        // if(nums.size()==1)
        // {
        //     if(nums[0]==target) return 0;
        //     else return -1;
        // }
        // for(int i =0;i<nums.size();i++)
        // {
        //     if(i+1==nums.size() || nums[i+1]<nums[i])
        //     k = i;
        // }

        // for(int i=0;i<nums.size();i++)
        // {
        //     if(nums[i]==target)
        //     if(k==0|| k == nums.size()-1) return i;
        //     else
        //     return (k+i)%(nums.size()-1);
        // }
        // return -1;
        int p = pivot(nums);
        // cout<<p<<endl;
        if(nums[p]<=target && target<=nums[nums.size()-1])
        return BinarySearch(nums,p,nums.size()-1,target);
        else return BinarySearch(nums,0,p,target);
    }
};