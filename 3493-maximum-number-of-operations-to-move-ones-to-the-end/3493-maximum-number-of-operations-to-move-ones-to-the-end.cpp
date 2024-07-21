class Solution {
public:
    int maxOperations(string s) {
        long long ans = 0;
        int one = 0,zero=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                if(zero)ans+=one;
                one++;
                zero = 0;
                
            }
            else{
                zero++;
            }
        }
        if(zero){
            ans+=one;
        }
        return ans;
    }
};