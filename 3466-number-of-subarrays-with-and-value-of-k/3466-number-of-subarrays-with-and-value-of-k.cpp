class Solution {
private:
    typedef long long int ll;
    int check(vector<ll>&bit_count,int k,int len){
        int ant = 0;
        for(int i=0;i<32;i++){
            if(bit_count[i]==len)ant |=(1<<i);
        }
        return ant;
    }
    ll atleastK(vector<int> &nums,int k){
        ll n = nums.size(),left = 0,right = 0,ans = 0,sub_and =nums[0];
        vector<ll> bit_count(32,0);
        while(right<n){
            for(int i=0;i<32;i++){
                if(nums[right]&(1<<i))bit_count[i]++;
            }
            while(left<=right && check(bit_count,k,right-left+1)<k){
                for(int i=0;i<32;i++){
                    if(nums[left]&(1<<i)){
                        bit_count[i]--;
                    }
                }
                left++;
            }
            // cout<<left<<" ";
            if(left<=right)ans += (right-left+1);
            right++;
        }
        return ans;
    }
public:
    long long countSubarrays(vector<int>& nums, int k) {
        // cout<<atleastK(nums,k)<<" "<<atleastK(nums,k+1);
        return atleastK(nums,k) - atleastK(nums,k+1);  
    }
};