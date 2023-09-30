class Solution {
private:
  void merge(vector<int>& nums1, vector<int>& nums2,vector<int> &merged){
    int i =0,j=0,k=0;
    while(i<nums1.size() && j<nums2.size()){
      if(nums1[i]>nums2[j])merged[k++]=nums2[j++];
      else merged[k++]=nums1[i++];
    }
    while(i<nums1.size())merged[k++]=nums1[i++];
    while(j<nums2.size())merged[k++]=nums2[j++];
  }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(),m = nums2.size();
        vector<int> merged(n+m,0);
        merge(nums1,nums2,merged);
        // for(auto it:merged)cout<<it<<" ";
        if((n+m)&1)return merged[(n+m)/2];
        else return (double)(merged[(n+m)/2]+merged[(n+m)/2-1])/2;
    }
};
