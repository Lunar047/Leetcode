class Solution {
public:
    // bool SearchM(vector<vector<int>>& mat,int si,int ei,int sj,int ej,int &t)
    // {
    //   cout<<si<<" "<<ei<<"   "<<sj<<" "<<ej<<" target "<<t<<endl;
    //   if(si>ei || sj>ej ) return false;
    //   int mi = si+(ei-si)/2;
    //   int mj = sj+(ej-sj)/2;
    //   cout<<mi<<"    "<<mj<<" midE "<<mat[mi][mj]<<endl;
    //   if(mat[mi][mj]==t)return true;
    //   else if(mat[mi][mj]>t) return SearchM(mat,si,mi,sj,mj-1,t);
    //   else return SearchM(mat,mi,ei,mj+1,ej,t);
    // }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // return SearchM(matrix,0,matrix.size()-1,0,matrix[0].size()-1,target);
        int s =0,c = matrix[0].size(),e = (matrix.size()*c-1),m = s+(e-s)/2;
        while(s<=e)
        {
          if(matrix[m/c][m%c]==target)return 1;
          else if(matrix[m/c][m%c]>target) e = m-1;
          else s = m+1;
          m = s+(e-s)/2;
        }
        return 0;
    }
};