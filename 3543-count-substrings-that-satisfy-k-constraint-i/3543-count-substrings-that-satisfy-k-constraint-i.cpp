class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int ans = 0,n = s.size();
        for(int i=0;i<n;i++){
            int o = 0,z = 0;
            for(int j=i;j<n;j++){
                if(s[j]=='1')o++;
                else z++;
                if(o<=k || z<=k)ans++;
                // else break;
            }
        }
        return ans;
    }
};