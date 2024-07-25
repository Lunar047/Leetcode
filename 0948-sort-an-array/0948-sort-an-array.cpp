class Solution {
private:
    void merge(int s,int mid,int e,vector<int> &nums){
        vector<int> temp(e-s+1,0);
        int i = 0,j = mid+1,k= s;
        while(s<=mid && j<=e){
            if(nums[s]<nums[j])temp[i++]  = nums[s++];
            else temp[i++] = nums[j++];
        }
        while(s<=mid)temp[i++] = nums[s++];
        while(j<=e)temp[i++] = nums[j++];
        for(int i=k;i<=e;i++)
            nums[i] = temp[i-k];
    }
    void mergeSort(int s,int e,vector<int> &nums){
       if(s<e){
        int mid = s+(e-s)/2;
        mergeSort(s,mid,nums);
        mergeSort(mid+1,e,nums);
        merge(s,mid,e,nums);
       }
    }
    int partition(int s,int e,vector<int> &nums){
        int pivot = nums[s],i = s,j = e;
       while(i<j){
        while(nums[i]<=pivot && i<e)i++;
        while(nums[j]>pivot && j>s) j--;
        if(i<j)swap(nums[i],nums[j]);
       }
       swap(nums[s],nums[j]);
       return j;
    }
    void quickSort(int s,int e,vector<int> &nums){
        // cout<<s<<" "<<e<<"\n";
        if(s<e){
            int pivot = partition(s,e,nums);
            quickSort(s,pivot-1,nums);
            quickSort(pivot+1,e,nums);
        }
    }
    bool isSorted(int &n,vector<int> &nums){
        for(int i = 0;i<n-1;i++){
            if(nums[i]>nums[i+1])return 0;
        }
        return 1;
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        if(isSorted(n,nums))return nums;
        // quickSort(0,n-1,nums);
        mergeSort(0,n-1,nums);
        return nums;
    }
};