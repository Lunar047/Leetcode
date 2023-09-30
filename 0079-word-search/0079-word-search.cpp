class Solution {
public:
    bool isSafe(int x,int y,int &r,int &c,vector<vector<int>> &visited)
    {
        // cout<<0<<endl;

        if((x>=0 && y>=0) && (x<c && y<r) && visited[y][x] == 0) return true;
        else return false;
    }
    bool solve(int x,int y,int &r,int &c, vector<vector<int>> &visited,vector<vector<char>>& board,int in,string &word)
    {
        if(in >= word.size()-1) return true;
        
        // else if(board[y][x]!=word[in]) return false;
        // cout<<1<<endl;
        visited[y][x] = 1;
        int nX=x,nY =y;
        // move right
        nX = x+1;
        nY = y;
        // cout<<2<<endl;
         if(isSafe(nX,nY,r,c,visited) && board[nY][nX] == word[in+1])
         {
          //  cout<<board[nY][nX]<<"  "<< word[in+1]<<endl;
            if(solve(nX,nY,r,c,visited,board,in+1,word))
            return true;

         }
        // cout<<3<<endl;
        // move down
         nX = x;
         nY = y+1;
         if(isSafe(nX,nY,r,c,visited) && board[nY][nX] == word[in+1])
         {
          //  cout<<board[nY][nX]<<"  "<< word[in+1]<<endl;
           if( solve(nX,nY,r,c,visited,board,in+1,word))
            return true;


         }

        // cout<<4<<endl;
        // move left
         nX = x-1;
         nY = y;
        if(isSafe(nX,nY,r,c,visited) && board[nY][nX] == word[in+1])
         {
        //  cout<<board[nY][nX]<<"  "<< word[in+1]<<endl;
         if(solve(nX,nY,r,c,visited,board,in+1,word))
            return true;


         }

        // cout<<5<<endl;
        // move up
         nX = x;
         nY = y-1;
         if(isSafe(nX,nY,r,c,visited) && board[nY][nX] == word[in+1])
         {
          //  cout<<board[nY][nX]<<"  "<< word[in+1]<<endl;
           if(solve(nX,nY,r,c,visited,board,in+1,word))
            return true;
           
         }
        
        // cout<<6<<endl;
         visited[y][x] = 0;
        // cout<<7<<endl;
      return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
      int r = board.size();
      int c = board[0].size();
      int n = max(r,c);
      vector<vector<int>> visited;
      for(int i =0;i<n;i++)
      {
        vector<int> t (n,0);
        visited.push_back(t);
      }
      for(int i =0;i<board.size();i++)
      for(int j =0;j< board[i].size();j++)
      {
      if(board[i][j]==word[0])
      {
        // cout<<i<<"  "<<j<<" "<<board[i][j]<<" "<<endl;
        if(solve(j,i,r,c,visited,board,0,word)) return true;
      }
      }
      return false;
    }
};