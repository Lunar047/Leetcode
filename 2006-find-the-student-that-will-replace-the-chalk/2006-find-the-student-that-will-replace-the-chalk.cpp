class Solution {
typedef long long ll;
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        ll sum = accumulate(chalk.begin(),chalk.end(),(ll)0);
        k%=sum;
        for(int i=0;i<chalk.size();i++){
            if(chalk[i]>k)return i;
            else k-=chalk[i];
        }
        return 0;
    }
};