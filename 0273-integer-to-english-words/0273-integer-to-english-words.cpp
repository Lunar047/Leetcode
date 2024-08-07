class Solution {
vector<string>  base = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
vector<string> ten = {"","Ten","Twenty","Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
vector<string> a = {"Hundred","Thousand","Million","Billion","Trillion"};
private:
    typedef long long ll;
    string solve(ll num){
        // cout<<num<<" ";
        string ans;
        if(num<=0)return ans;
        if(num<20)return base[num];
        else if(num<100){
            ans += (ten[num/10]);
            if(num%10)ans =  ans+" "+solve(num%10);
        }
        else if(num<1e3){
            ans+= (base[num/1e2] +" "+ a[0]);
            if(num%100)ans =  ans +" "+ solve(num%100);
        }
        else if(num<1e6){
            ans += (solve(num/1e3)+ " "+a[1]);
            if(num%1000)ans = ans+ +" "+solve(num%1000);
        }
        else if(num<1e9){
            ans+= (solve(num/1e6)+" "+a[2]);
            if(num%1000000)ans = ans+ +" "+solve(num%1000000);
        }
        else if(num<1e12){
            ans+= (solve(num/1e9)+" "+a[3]);
            if(num%1000000000)ans = ans+" "+solve(num%1000000000);

        }
        return ans;
    }
public:
    string numberToWords(int num) {
       if(num==0)return base[0];
       ll d_num = num;
       return solve(d_num);
    }   
};