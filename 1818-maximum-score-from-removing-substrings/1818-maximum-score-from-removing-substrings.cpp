class Solution {
private:
    int ans = 0;
    string remove(string &s,int x,string str){
        int n = s.size();
        stack<char> st;
        for(int i=0;i<n;i++){
            if(s[i]==str[1]){
                if(!st.empty() && st.top()==str[0]){
                    ans+=x;
                    st.pop();
                }
                else st.push(s[i]);
            }
            else st.push(s[i]);
        }
        string temp;
        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
public:
    int maximumGain(string s, int x, int y) {
        int n = s.size();
        if(x>y){
            s = remove(s,x,"ab");
            s = remove(s,y,"ba");
        }
        else{
            s = remove(s,y,"ba");
            s = remove(s,x,"ab");
        }
        return ans;
    }
};