class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> st;
        for(string i:logs){
            if(i[0]=='.'){
                if(i[1]=='.')if(st.size())st.pop();
            }
            else{st.push(i);}
        }
        return st.size();
    }
};