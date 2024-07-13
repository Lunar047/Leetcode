class Solution {
public:
    bool isValid(string s) {
       stack<char> st;
       for(char &c:s){
            if(c==')'){
                if(!st.empty() && st.top()=='(')st.pop();
                else return 0;
            }
            else if(c=='}'){
                if(!st.empty() && st.top()=='{')st.pop();
                else return 0;
            }
            else if(c==']'){
                if(!st.empty() && st.top()=='[')st.pop();
                else return 0;
            }
            else st.push(c);
       }
       if(!st.empty())return 0;
       return 1;
    }
};