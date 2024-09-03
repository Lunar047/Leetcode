class Solution {
public:
    int getLucky(string s, int k) {
        if(!k){
            return stoi(s);
        }
        string temp;
        for(auto &i:s){
            temp+=to_string((int)(i-'a'+1));
            // temp.push_back('0'+(i-'a'+1));
        }

        while(k--){
            int ans = 0;
            for(auto &i:temp){
                ans+=(i-'0');
            }
            temp = to_string(ans);
        }
        // cout<<temp;
        return stoi(temp);
    }
};