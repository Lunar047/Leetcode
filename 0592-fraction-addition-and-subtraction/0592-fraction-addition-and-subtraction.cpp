class Solution {
public:
    string fractionAddition(string expression) {
        vector<int> num,dem;
        size_t  i =0,n = expression.size();
        int sign = 1;
        string temp;
        while(i<n){
            if(expression[i]=='+')sign = 1;
            else if(expression[i]=='-')sign = -1;
            else if(expression[i]=='/'){
                // cout<<temp<<" ";
                num.push_back(sign*stoi(temp));
                temp.clear();
               string s;
               i++;
               while(i<n && isdigit(expression[i])){
                s.push_back(expression[i++]);
               }
            //    cout<<s<<":  ";
                dem.push_back(stoi(s));
               i--;
            }
            else{
                temp.push_back(expression[i]);
            }
            i++;
        }
        // cout<<endl;
        // for(int j=0;j<num.size();j++){
        //     cout<<num[j]<<" "<<dem[j]<<endl;
        // }
        int p = num[0],q = dem[0];
        for(int j = 1;j<num.size();j++){
            int lcm = (q*dem[j])/(__gcd(q,dem[j]));
            p = p * (lcm/q) + num[j] *(lcm/dem[j]);
            q = lcm;
        }
        if(!p)return "0/1";
        else{
            int g = __gcd(abs(p),abs(q));
                p/=g;
                q/=g;
            return to_string(p)+"/"+to_string(q);
        }
    }
};