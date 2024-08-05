class NumArray {
private:
    vector<int> fen,A;
    int n;
    void add(int idx,int delta){
            for(idx;idx<=n; idx += (idx &(-idx))){
                fen[idx]+=delta;
               
            }
    }
    void sub(int idx,int delta){
        for(idx;idx<=n;idx+= idx & (-idx)){
            fen[idx]-=delta;
        }
    }
    int sum(int idx){
        int ret = 0;
        for(idx;idx>0;idx-=(idx&(-idx))){
            ret += fen[idx];    
        }
        return ret;
    }
public:
    NumArray(vector<int>& nums) {
        A = nums;
        n = nums.size();
        fen.assign(n+2,0);
        for(int i=0;i<n;i++){
            add(i+1,nums[i]);
        }
        // for(auto &i:fen)cout<<i<<" ";
        // cout<<endl;
    }
    
    void update(int index, int val) {
        sub(index+1,A[index]);
        A[index] = val;
        add(index+1,val);
    }
    
    int sumRange(int left, int right) {
        return sum(right+1) - sum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */