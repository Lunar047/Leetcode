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
    void quickSort(int s,int e,vector<int> &nums){
        cout<<s<<" "<<e<<"\n";
        if(s<e){
            int pivot = partition(s,e,nums);
            quickSort(s,pivot-1,nums);
            quickSort(pivot+1,e,nums);
        }
    }
    int partition(int s,int e,vector<int> &nums){
        int pivot = nums[e],i = s,j = e;
       while(i<j){
        if(nums[i]<=pivot && i<e)i++;
        else if(nums[j]>pivot && j>s) j--;
        else swap(nums[i],nums[j]);
       }
       swap(nums[e],nums[j]);
       return j;
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        // quickSort(0,n-1,nums);
        mergeSort(0,n-1,nums);
        return nums;
    }
};