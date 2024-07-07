class Solution {
private:
    int n,m,dr[4] = {0,1,0,-1},dc[4] = {1,0,-1,0};
    bool check(int in,int i,int j,vector<vector<char>>& board, string &word,vector<vector<int>> &vis){
        if(in>=word.size())return 1;
        vis[i][j] = 1;
        for(int k=0;k<4;k++){
            int ni = i + dr[k],nj =j+dc[k];
            if(ni>=0 && ni<n && nj>=0 && nj<m && board[ni][nj]==word[in] && !vis[ni][nj]){
                if(check(in+1,ni,nj,board,word,vis))return 1;
            }
        }
        vis[i][j] = 0;
        return 0;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(),m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(check(1,i,j,board,word,vis))return 1;
                }
            }
        }
        return 0;
    }
};