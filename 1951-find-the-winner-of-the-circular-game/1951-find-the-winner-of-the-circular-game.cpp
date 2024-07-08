class Solution {
private:
    int solve(queue<int> &q,int k,int cnt){
        if(q.size()==1)return q.front();
        int n = q.size();
        for(int i=1;i<=n;i++){
            cout<<q.front()<<" ";
            if(k%i)q.push(q.front());
            q.pop();
        }
        cout<<endl;
        return solve(q,k,cnt);
    }
public:
    int findTheWinner(int n, int k) {
        if(n==1)return 1;
        queue<int> q;
        for(int i=1;i<=n;i++)q.push(i);
        int cnt = 0;
        while(q.size()>1){
            cnt++;
            // cout<<q.front()<<" "<<cnt<<endl;
            if(cnt==k){
                cnt = 0;
                // cout<<endl;
            }
            else q.push(q.front());
            q.pop();
        }
        return q.front();
    }
};