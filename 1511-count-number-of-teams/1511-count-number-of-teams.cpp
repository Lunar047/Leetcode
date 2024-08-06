class Solution {
private:
    int n,mx;
    vector<int> fen1,fen2;
    void update(int idx,vector<int>&fen,bool i){
        for(idx;idx<=mx;idx+=idx&-idx){
            if(i)fen[idx]++;
            else fen[idx]--;
        }
    }
    int sum(int idx,vector<int>&fen){
        int res = 0;
        for(idx;idx>0;idx-=idx&-idx){
            res+=fen[idx];
        }
        return res;
    }
public:
    int numTeams(vector<int>& rating) {
        n = rating.size();
        mx = *max_element(rating.begin(),rating.end());
        fen1.assign(mx+10,0);
        fen2.assign(mx+10,0);
        for(int i=n-1;i>=0;i--){
            update(rating[i],fen2,1);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
           update(rating[i],fen2,0);
           int left_small = sum(rating[i]-1,fen1);
           int right_small = sum(rating[i]-1,fen2);
           int left_greater = sum(mx,fen1) - sum(rating[i]-1,fen1);
           int right_greater = sum(mx,fen2)-sum(rating[i]-1,fen2);
           update(rating[i],fen1,1);
            ans += (left_small*right_greater + left_greater*right_small);
        }
        return ans;
    }
};