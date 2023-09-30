class Solution {
public:
    int lowerBound(vector<int>&num,int s,int e,int t)
    {
      if(s>e)
      {
         return -1;
      }
       int m = s+(e-s)/2;
       if((m==0 || num[m-1]<t) && num[m]==t)
       {
          return m;
       }
       else if(num[m]>=t)
       {
          return lowerBound(num,s,m-1,t);
       }
       else
       {
          return lowerBound(num,m+1,e,t);
       }
    }
    int upperBound(vector<int> &num,int s,int e,int t)
    {
       if(s>e)
      {
         return -1;
      }
       int m= s+(e-s)/2;
       if((m==num.size()-1 || num[m+1]>t) && num[m]==t)
       {
          return m;
       }
       else if(num[m]>t)
       {
          return upperBound(num,s,m-1,t);
       }
       else
       {
          return upperBound(num,m+1,e,t);
       }

    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2);
        ans[0] = lowerBound(nums,0,nums.size()-1,target);
        ans[1] = upperBound(nums,0,nums.size()-1,target);
        return ans;
    }
};