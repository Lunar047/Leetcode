class Solution {
public:
    string getSmallestString(string s) {
        int n= s.size();
        for(int i=0;i<n-1;i++){
            int a = s[i]-'0',b = s[i+1]-'0';
            if((a&1 && b&1) || (!(a&1) && !(b&1))){
                if(a>b){
                    swap(s[i],s[i+1]);
                    break;
                }
            }
        }
        return s;
    }
};