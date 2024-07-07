class Solution {
private:
    bool check(map<char,int>&mp,vector<int>&cnt){
        for(auto &i:mp){
            if(cnt[i.first-'a']!=i.second)return 0;
        }
        return 1;
    }
public:
    vector<int> partitionLabels(string s) {
        vector<int> cnt(26,0);
        int n = s.size();
        for(auto &i:s)cnt[i-'a']++;
        // for(auto &i:cnt)cout<<i<<" ";
        vector<int> ans;
        int current = -1,previous = 0;
        map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            if(check(mp,cnt)){
                for(auto &i:mp){
                    i.second = 0;
                    cnt[i.first-'a'] = 0;
                }
                ans.push_back(i-previous+1);
                previous =i+1;
            }
        }
        return ans;
    }
};