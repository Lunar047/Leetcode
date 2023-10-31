class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int x = pref[0];
        for(int i=1;i<pref.size();i++){
            int t = pref[i];
           pref[i] = pref[i]^x;
           x = t;
        }
        return pref;
    }
};