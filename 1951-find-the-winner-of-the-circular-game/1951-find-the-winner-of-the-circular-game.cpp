class Solution {

public:
    int findTheWinner(int n, int k) {
        if(n==1)return 1;
        queue<int> q;
        for(int i=1;i<=n;i++)q.push(i);
        int cnt = 0;
        while(q.size()>1){
            cnt++;
            if(cnt==k){
                cnt = 0;
            }
            else q.push(q.front());
            q.pop();
        }
        return q.front();
    }
};