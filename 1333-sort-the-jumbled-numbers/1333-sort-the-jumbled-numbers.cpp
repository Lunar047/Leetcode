class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                v.push_back({mapping[0],i});
            }
            else{
                string t = to_string(nums[i]);
                // cout<<t<<" ";
                for(int i=0;i<t.size();i++){
                    t[i] ='0'+mapping[t[i]-'0'];
                }
                v.push_back({stoi(t),i});
            }
        }
        sort(v.begin(),v.end());
        vector<int> ans;
        for(auto &i:v){
            ans.push_back(nums[i.second]);
        }
        return ans;
    }
};