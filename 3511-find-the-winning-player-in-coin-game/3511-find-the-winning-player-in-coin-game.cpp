class Solution {
public:
    string losingPlayer(int x, int y) {
        string a = "Alice",b = "Bob";
        bool f = 0;
        while(x>0 && y>0){
            if(x>=1 && y>=4){
                x--;
                y-=4;
                f = !f;
            }
            else break;
        }
        if(f)return a;
        else return b;
    }
};