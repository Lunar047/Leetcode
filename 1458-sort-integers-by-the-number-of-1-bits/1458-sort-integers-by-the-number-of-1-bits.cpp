class Solution {
private:
    int coutBit(int n){
        int c =0;
        for(int i=0;i<32;i++){
            if(n&1)c++;
            n>>=1;
        }
        return c;
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> st;
        for(int i=0;i<arr.size();i++){
            st.push({coutBit(arr[i]),arr[i]});
        }
        int i=0;
        while(!st.empty()){
            arr[i++]=st.top().second;
            st.pop();
        }
        return arr;
    }
};