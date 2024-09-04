class Solution {
private:
    map<pair<int,int>,bool> mp; 
    int n;
    int ans = 0;
    void solve(int i,int &x,int &y,int dx,int dy,vector<int>& commands){
        for(i=0;i<n;i++){
            if(commands[i]==-2){
                    int x_n = 0*dx + dy * -1,y_n = 1*dx + 0*dy;
                    dx = x_n;
                    dy = y_n;
            }
            else if(commands[i]==-1){
               int x_n = 0*dx + dy * 1,y_n = -1*dx + 0*dy;
                dx = x_n;
                dy = y_n;
            }
            else{
                for(int j=0;j<commands[i];j++){
                    if(mp.count({x+dx,y+dy}))break;
                    x+=dx;
                    y+=dy;
                }
            }
            ans = max(ans,(x*x) + (y*y));
            // cout<<x<<" "<<y<<" "<<dx<<" "<<dy<<endl;
        }
    }
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x= 0,y = 0;
        n = commands.size();
        for(auto &i:obstacles){
            mp[{i[0],i[1]}] = 1;
        }
        solve(0,x,y,0,1,commands);
        return ans;
    }
};