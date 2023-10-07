class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        long long atleastK = 0,atleastK1 =0;
        int left = 0,right =0;
        unordered_map<int,int> umap;
        while(right<n){
            umap[nums[right]]++;
            while(umap.size()==k){
                atleastK += (n-right);
                umap[nums[left]]--;
                if(umap[nums[left]]==0)umap.erase(nums[left]);
                left++;
            }
            right++;
        }
        left = right =0;
        umap.clear();
        while(right<n){
            umap[nums[right]]++;
            while(umap.size()==k+1){
                atleastK1 += (n-right);
                umap[nums[left]]--;
                if(umap[nums[left]]==0)umap.erase(nums[left]);
                left++;
            }
            right++;
        }
        return atleastK-atleastK1;
    }
};