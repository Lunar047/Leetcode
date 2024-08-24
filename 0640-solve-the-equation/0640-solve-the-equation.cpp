class Solution {
public:
    string solveEquation(string equation) {
        int sign = 1,x_cnt=0,nx_sign = 1,ans=0;
        string temp;
        for(auto &i:equation){
            if(i=='='){
                if(temp.size()){
            
                    ans+=(sign*nx_sign*stoi(temp));
                    // cout<<temp<<" :"<<ans<<endl;
                    temp.clear();
                }
                sign*=-1;
                nx_sign = 1;
            }
            else if(i=='x'){
                if(temp.size()){
                    x_cnt+=(nx_sign*sign*stoi(temp));
                    temp.clear();
                }
                else x_cnt+=(nx_sign*sign);
                // cout<<x_cnt<<" ";
            }
            else if(i=='+'){
                if(temp.size()){
                    ans+=(sign*nx_sign*stoi(temp));
                    // cout<<temp<<" :"<<ans<<endl;
                    temp.clear();
                }
                nx_sign = 1;
            }
            else if(i=='-'){
                if(temp.size()){
                    
                    ans+=(sign*nx_sign*stoi(temp));
                    // cout<<temp<<" :"<<ans<<endl;
                    temp.clear();
                }
                nx_sign = -1;
            }
            else{
                temp.push_back(i);
            }
        }
        if(temp.size()){
            
            ans+=(sign*nx_sign*stoi(temp));
            // cout<<temp<<" :"<<ans<<endl;
            temp.clear();
        }
        // cout<<ans<<" "<<x_cnt<<endl;
        if(x_cnt==0){
            if(ans)return "No solution";
            return "Infinite solutions";
        }
        else{
            ans*=-1;
            ans/=x_cnt;
            return "x="+to_string(ans);
        }
    }
};