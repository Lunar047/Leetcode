class Solution {
private:
    map<pair<int,int>,bool> mp; 
    int n;
    int ans = 0;
    void rotate_right(int &x,int &y){
        int x_n = 0*x + y * 1,y_n = -1*x + 0*y;
        x = x_n;
        y = y_n;
    }
    void rotate_left(int &x,int &y){
        int x_n = 0*x + y * -1,y_n = 1*x + 0*y;
        x = x_n;
        y = y_n;
    }
    void solve(int i,int &x,int &y,int dx,int dy,vector<int>& commands){
        cout<<n<<endl;
        for(i=0;i<n;i++){
            if(commands[i]==-2){
                rotate_left(dx,dy);
            }
            else if(commands[i]==-1){
                rotate_right(dx,dy);
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