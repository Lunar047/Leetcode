class Solution {
public:
    int minChanges(int n, int k) {
        int ans = 0;
        int d = n^k;
        for(int i=0;i<32;i++){
            if(d&(1<<i)){
                if(n&(1<<i))ans++;
                else return -1;
            }
        }
        return ans;
    }
};