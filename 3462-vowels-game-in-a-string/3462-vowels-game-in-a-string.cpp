class Solution {
public:
    bool doesAliceWin(string s) {
        long long v = 0;
        for(auto &c:s){
            if(c=='a' || c=='e' || c=='i' || c=='o'|| c=='u')v++;
        }
        if(v==0)return 0;
        else return 1;
    }

};