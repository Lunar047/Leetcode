class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five_count =0,ten_count = 0;
        for(auto &i:bills){
            if(i==5)five_count++;
            else if(i==10){
                if(five_count){
                    five_count--;
                    ten_count++;
                }
                else return 0;
            }
            else{
                if(ten_count && five_count){
                    ten_count--;
                    five_count--;
                }
                else if(five_count>2)five_count-=3;
                else return 0;
            }
        }
        return 1;
    }
};