class Solution {
public:
    bool winnerOfGame(string colors) {
        int a=0,b=0,n=colors.size();
        for(int i=1;i<n-1;i++){
            if(colors[i]=='A')
            if(colors[i-1]=='A' && colors[i+1]=='A')a++;
        }
         for(int i=1;i<n-1;i++){
            if(colors[i]=='B')
            if(colors[i-1]=='B' && colors[i+1]=='B')b++;
        }
        return a>b;
    }
};