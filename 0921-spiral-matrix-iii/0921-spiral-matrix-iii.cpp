class Solution {
private:
    bool check(int i,int j,int &n,int &m){
        if(i>=0 && j>=0 && i<n && j<m)return 1;
        else return 0;
    }
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        ans.push_back({rStart,cStart});
        int k = 1,count = 1;
        while(count<(rows*cols)){
            for(int i=0;i<k;i++){
                if(k&1){
                    cStart++;
                }
                else{
                    cStart--;
                }
                if(check(rStart,cStart,rows,cols)){
                    count++;
                    ans.push_back({rStart,cStart});
                }
            }
            for(int i=0;i<k;i++){
                if(k&1){
                    rStart++;
                }
                else{
                    rStart--;
                }
                if(check(rStart,cStart,rows,cols)){
                    count++;
                    ans.push_back({rStart,cStart});
                }
            }
            k++;
        }
        return ans;
    }
};