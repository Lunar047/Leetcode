class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> cnt;
        for(auto &i:arr){
            cnt[i]++;
        }
        for(auto &i:arr){
            if(cnt[i]==1){
                k--;
                if(!k)return i;
            }
        }
        return "";
    }
};