// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
class Solution {
private:
    //for PBDS uncomment these lines
    // typedef tree<long long int, null_type, less_equal<long long int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
    vector<int> count;
    typedef pair<int,int> pii;
    void mergeSort(int left,int right,vector<pii> &nums){
        if(left<right){
        int mid = left + (right-left)/2;
        mergeSort(left,mid,nums);
        mergeSort(mid+1,right,nums);
        merge(left,mid,right,nums);
        }
    }
    void merge(int left,int mid,int right,vector<pii>&nums){
        vector<pii> temp(right-left+1);
        int i = left,j = mid+1,k=0;
        while(i<=mid && j<=right){
            if(nums[i].first>nums[j].first){
                count[nums[i].second]+=(right-j+1);// As right side of array is also sorted therefore number of element smaller that current i will be right - j + 1
                temp[k++] = nums[i++];
            }
            else temp[k++] = (nums[j++]);
        }
        while(i<=mid)temp[k++] = (nums[i++]);
        while(j<=right)temp[k++] = (nums[j++]);
        for(int i=left;i<=right;i++)nums[i] = temp[i-left];
    }
        // Fenwick Tree
        int no_of_smaller_element(int num,vector<int>&fen){
            int cnt = 0;
            for(num;num>0;num-=num&-num){
                cnt+=fen[num];
            }
            return cnt;
        }
        void update(int num,vector<int> &fen){
            for(num;num<=fen.size();num+=num&-num)fen[num]++;
        }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        count.assign(n,0);
        // ordered set approach
        // pbds A;
        // Merge sort approach
        // vector<pii> temp;
        // for(int i=0;i<n;i++){
        //     temp.push_back({nums[i],i});
        // }
        // mergeSort(0,n-1,temp);
        // for(auto &i:temp)cout<<i.first<<" ";
        // for(int i= n-1;i>=0;i--){
        //     A.insert(nums[i]);
        //     count[i] = A.order_of_key(nums[i]);
        // }
        // Fenwick Tree approach
        int mx = *max_element(nums.begin(),nums.end()),mn = *min_element(nums.begin(),nums.end());
        vector<int> fen(2e4+10,0);
        for(int i=n-1;i>=0;i--){
            count[i] = no_of_smaller_element(nums[i]-mn,fen);
            update(nums[i]-mn+1,fen);
        }
        return count;
    }
};