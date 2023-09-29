class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        vector<vector<bool>> v(n,vector<bool>(n,0));
        for(auto it:dig){
            v[it[0]][it[1]]=1;
        }
        int ans = 0;
        for(auto it:artifacts){
            int r1= it[0],c1=it[1],r2=it[2],c2=it[3];
            if(r1==r2){
                bool f =1;
                for(int i= c1;i<=c2;i++){
                    if(!v[r1][i]){
                        f = 0;
                        break;
                    }
                }
                if(f)ans++;
            }
            else if(c1==c2){
                bool f =1;
                for(int i = r1;i<=r2;i++){
                    if(!v[i][c1]){
                        f = 0;
                        break;
                    }
                }
                if(f)ans++;
            }
            else{
                bool f = 1;
                for(int i=r1;i<=r2;i++){
                    for(int j=c1;j<=c2;j++){
                        if(!v[i][j]){
                            f =0 ;
                            break;
                        }
                    }
                }
                if(f)ans++;
            }

        }
        return ans;
    }
};