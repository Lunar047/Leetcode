class Solution {
typedef long long int ll;
#define pii pair<int,int>
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        unordered_map<int,int> mp;//mapping of positions and robot number
        for(int i=0;i<n;i++){
            mp[positions[i]] = i;
        }
        sort(positions.begin(),positions.end());
        stack<int> st;
        for(int i=0;i<n;i++){
            int ind = mp[positions[i]],health = healths[ind];
            if(directions[ind]=='R'){
                st.push(ind);
            }
            else{
                // cout<<ind<<":"<<positions[ind]<<"  ";
                while(!st.empty() && healths[ind]>0){
                    // cout<<st.top()<<" ";
                    if(healths[ind]>healths[st.top()]){
                        healths[st.top()] = 0;
                        st.pop();
                        healths[ind]--;
                    }
                    else if(healths[ind]==healths[st.top()]){
                        healths[st.top()] = 0;
                        st.pop();
                        healths[ind] = 0;
                    }
                    else{
                        healths[ind] = 0;
                        healths[st.top()]--;
                        if(healths[st.top()]==0)st.pop();
                    }
                }
            }
        }
        vector<int> ans;
        for(auto &i:healths){
            if(i>0)ans.push_back(i);
        }
        return ans;
    }
};