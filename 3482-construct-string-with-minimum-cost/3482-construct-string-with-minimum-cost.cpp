struct node{
    node *link[26];
    bool f;
    int cost;
    node(){
        for(int i=0;i<26;i++)link[i] = nullptr;
        f=0;
        cost =1e9;
    }
};
class Solution {
private:
    typedef long long ll;
    ll n,m;
    class Trie{
        private:
        public:
            node *root;
            Trie(){
                root = new node();
            }
            void insert(string &s,int &cost){
                node *ptr = root;
                for(auto &i:s){
                    int index = i-'a';
                    if(!ptr->link[index])ptr->link[index] = new node();
                    ptr = ptr->link[index];
                }
                ptr->f = 1;
                ptr->cost =  min(cost,ptr->cost);
            }
    };
public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        n = target.size(),m = words.size();
        Trie T;
       for(int i=0;i<m;i++){
            T.insert(words[i],costs[i]);
       }
       vector<ll>dp(n+1,1e9);
       dp[0]=0;
       for(int i=0;i<n;i++){
            if(dp[i]==1e9)continue;
            node*ptr = T.root;
                for(int j=i;j<n;j++){
                    // cout<<j<<" ";
                    if(!ptr->link[target[j]-'a'])break;
                    ptr = ptr->link[target[j]-'a'];
                    dp[j+1] = min(dp[j+1],dp[i]+ptr->cost);
                }
                // cout<<endl;
       }
    //    for(auto &i:dp)cout<<i<<" ";
       if(dp[n]>=1e9)return -1;
       else return dp[n];
    }
};