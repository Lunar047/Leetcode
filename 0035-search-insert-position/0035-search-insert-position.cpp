class Solution {
public:
    int binarySearch(vector<int> num,int s,int e,int t)
    {
        if(s>e)
        return s;
        int m = e-(e-s)/2;
        if(num[m]==t)
        return m;
        else if(num[m]>t)
        return binarySearch(num,s,m-1,t);
        else return binarySearch(num,m+1,e,t);
    }
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums,0,nums.size()-1,target);
        
    }
};