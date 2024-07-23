class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int n = nums.size(),k=0;
        vector<vector<long long>> cnt(10,vector<long long>(10,0));
        for(auto &i:nums){
            k=0;
            while(i>0){
                cnt[k++][i%10]++;
                i/=10;
            }
        }
        long long ans =0;
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                if(cnt[i][j]){
                    ans += cnt[i][j]*(n-cnt[i][j]);
                }
            }
        }
        return ans>>1;
    }
};