class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26,0);
        for(auto &i:s){
            freq[i-'a']++;
        }
        long long ans = 0;
        for(auto &i:freq){
            if(i<3)ans+=i;
            else if(i&1)ans++;
            else ans+=2;
        }
        return ans;
    }
};