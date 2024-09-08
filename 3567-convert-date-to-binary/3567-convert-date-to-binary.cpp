class Solution {
private:
    string dec_to_bin(string a){
        int b = stoi(a);
        string ans;
        while(b>0){
            if(b&1)ans.push_back('1');
            else ans.push_back('0');
            b>>=1;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
public:
    string convertDateToBinary(string date) {
        string temp, ans;
        for(auto &i:date){
            if(i=='-'){
                temp = dec_to_bin(temp);
                ans+=temp;
                temp.clear();
                ans.push_back('-');
            }
            else temp.push_back(i);
        }
        temp = dec_to_bin(temp);
        ans+=temp;
        // ans.pop_back();
        return ans;
    }
};