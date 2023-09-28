class Solution {
public:
    string removeDuplicateLetters(string s) {
         vector<int> v(26,0),v2(26,0);
        stack<char> st;
        for(int i=0;i<s.size();i++){
            v[s[i]-'a']++;
        }
        for(int i=0;i<s.size();i++){
            v[s[i]-'a']--;
            if(v2[s[i]-'a'])continue;
            while(!st.empty() && (st.top()>s[i] && v[st.top()-'a']) ){
               v2[st.top()-'a'] = 0;
               st.pop();
           }
               v2[s[i]-'a'] = 1;
                st.push(s[i]);

        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};