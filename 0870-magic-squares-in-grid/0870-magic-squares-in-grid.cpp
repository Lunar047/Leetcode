class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        if(n<3 || m<3)return 0;
        vector<int> rSum(3,0),cSum(3,0);
        int bit = 0,one_nine=0,dia1 =0,dia2=0;
        for(int i=1;i<10;i++){
            one_nine|=(1<<i);
        }
        // cout<<one_nine<<" \n";
        int ans = 0;
        for(int i=0;i<n-2;i++){
            for(int j=0;j<m-2;j++){
                bit = dia1 = dia2 =0;
                fill(rSum.begin(),rSum.end(),0);
                fill(cSum.begin(),cSum.end(),0);
                for(int k=0;k<3;k++){
                    for(int l =0;l<3;l++){
                        if(k==l)dia1+=grid[i+k][j+l];
                        if(k+l==2)dia2+=grid[i+k][j+l];
                        rSum[(i+k)%3]+=grid[i+k][j+l];
                        cSum[(j+l)%3]+=grid[i+k][j+l];
                        bit |= (1<<grid[i+k][j+l]);
                    }
                }
                if(bit==one_nine){
                    // cout<<"HI\n";
                    bool f = 1;
                    for(int i=1;i<3;i++){
                        if(rSum[i]^rSum[i-1])f = 0;
                        if(cSum[i]^cSum[i-1])f=0;
                    }
                    if(f && dia1==dia2)ans++;
                }
            }
        }
        return ans;
    }
};