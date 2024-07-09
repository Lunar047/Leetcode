class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long int current_time = 0,n= customers.size();
        double avg_time = 0;
        long long int wait_time = 0;
        for(auto &i:customers){
            if(current_time>i[0]){
                wait_time += (current_time-i[0]+i[1]);
            }
            else{
                wait_time += (i[1]);
            }
            current_time = max((long long)i[0]+i[1],current_time+i[1]);
        }
        avg_time = (double)wait_time/(double)n;
        return avg_time;
    }
};