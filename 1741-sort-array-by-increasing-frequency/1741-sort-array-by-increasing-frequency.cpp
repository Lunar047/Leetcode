class Solution {
private:
    typedef pair<int,int> pii;
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> mp;
        for(auto &i:nums)mp[i]++;
        vector<pii> v;
        for(auto &i:mp)v.push_back(i);
        sort(v.begin(),v.end(),[this](pii &a,pii &b){
            if(a.second>b.second)return false;
            else if(a.second==b.second)return a.first>=b.first;
            else return true;
        });
        vector<int> ans;
        for(auto &i:v){
            while(i.second--){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};