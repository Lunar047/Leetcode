class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int it = 0,j=0;
        for(auto &i:commands){
            if(i=="RIGHT")j++;
            else if(i=="LEFT")j--;
            else if(i=="UP")it--;
            else it++;
        }
        return n*it+j;
    }
};