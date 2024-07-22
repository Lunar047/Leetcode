class Solution {
private:
    typedef pair<int,int> pii;
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pii> h;
        for(int i=0;i<heights.size();i++){
            h.push_back({heights[i],i});
        }
        sort(h.rbegin(),h.rend());
        vector<string> ans;
        for(auto &i:h){
            ans.push_back(names[i.second]);
        }
        return ans;
    }
};