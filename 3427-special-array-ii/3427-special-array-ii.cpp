class Solution {
private:
    vector<bool> seg;
    int n;
    bool parity(int &a,int &b){
        if((a&1 && !(b&1)) || (b&1 && !(a&1)))return 1;
        else return 0;
    }
    void build(int index,int low,int high,vector<int>&nums){
        // cout<<index<<" ";
        // cout<<low<<" "<<high<<" \n"; 
        if(high==low){
            seg[index] = 1;
            return;
        }
        // else if(high<low)return;
        int mid = (high+low)/2;
        build(2*index+1,low,mid,nums);
        build(2*index+2,mid+1,high,nums);
        seg[index] = seg[2*index+1] & seg[2*index+2] & parity(nums[mid],nums[mid+1]);
    }
    bool query(int i,int tl,int tr,int l,int r,vector<int> &nums){
        if (l > r) return 1;
        if (l == tl && r == tr) {
            return seg[i];
        }
        int tm = (tl + tr) / 2;
        bool f = (r>tm && l<=tm)?(parity(nums[tm],nums[tm+1])):1;
        // cout<<f<<" ";
        // cout<<tm<<" "<<nums[tm]<<" "<<nums[tm+1]<<" "<<parity(nums[tm],nums[tm+1])<<":\n";
        return f & query(i*2+1, tl, tm, l, min(r, tm),nums) & query(i*2+2, tm+1, tr, max(l, tm+1), r,nums);
    }

public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        n = nums.size();
        seg.resize(4*n+1,0);
        vector<bool> ans;
        build(0,0,n-1,nums);
        // for(auto i:seg)cout<<i<<" ";
        // cout<<endl;
        int q = queries.size();
        for(int i=0;i<q;i++){
            ans.push_back(query(0,0,n-1,queries[i][0],queries[i][1],nums));
            // cout<<endl;
        }
        return ans;
    }
};