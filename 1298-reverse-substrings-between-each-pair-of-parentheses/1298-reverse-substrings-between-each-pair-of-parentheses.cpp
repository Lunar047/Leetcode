class Solution {
public:
    string reverseParentheses(string s) {
        string ans,cur;
        stack<char> st;
        for(char &c:s){
            if(c==')'){
                string cur;
                while(!st.empty() && st.top()!='('){
                    cur.push_back(st.top());
                    st.pop();
                }
                if(st.size())st.pop();
                for(auto &i:cur)st.push(i);
            }
            else st.push(c);
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};