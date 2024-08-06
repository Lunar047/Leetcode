class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26,0);
        for(char &c:word){
            freq[c-'a']++;
        }
        sort(freq.rbegin(),freq.rend());
        int ans = 0,k =9-2+1,m=1;
        for(auto &i:freq){
            if(!k){
                m++;
                k =8;
            }
            ans+=(i*m);
            k--;
        }
        return ans;
    }
};