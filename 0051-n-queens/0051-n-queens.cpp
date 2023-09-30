class Solution {
private:
    bool isSafe(int r,int c,vector<vector<int>> &board,int n){
        int nr =r,nc =c;
        while(nc>=0)if(board[nr][nc--])return false;
        nc =c;
        while(nc>=0 && nr>=0)if(board[nr--][nc--])return false;
        nr =r;
        nc =c;
        while(nc>=0 && nr<n)if(board[nr++][nc--])return false;
        return true;
    }
     // function to check whether the position is safe or not 
//     bool isSafe(int row, int col,vector<vector<int>> &board,int N) 
//    { 
//     int i, j; 
//     for (i = 0; i < col; i++) 
//         if (board[row][i]) 
//             return false; 

//     for (i = row, j = col; i >= 0 && j >= 0; i--, j--) 
//         if (board[i][j]) 
//             return false; 
//     for (i = row, j = col; j >= 0 && i < N; i++, j--) 
//         if (board[i][j]) 
//             return false; 
  
//     return true; 
//   } 
    void printA(vector<vector<int>> &b,int n){
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<b[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
    void solve(int col,vector<vector<string>> &ans,vector<vector<int>> &board,int &n)
    {
        if(col>=n){
            // cout<<col<<endl;
            // printA(board,n);
            vector<string> t;
            for(int i=0;i<n;i++){
                string p = "";
                for(int j=0;j<n;j++){
                    if(board[i][j])p.push_back('Q');
                    else p.push_back('.');
                }
                t.push_back(p);
            }
            ans.push_back(t);
            return;
        }
        for(int row = 0;row<n;row++){
            if(isSafe(row,col,board,n)){
                // cout<<row<<" "<<col<<endl;
                board[row][col]=1;
                solve(col+1,ans,board,n);
                board[row][col]=0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<int>> board(n,vector<int>(n,0));
        solve(0,ans,board,n);
        return ans;
    }
};