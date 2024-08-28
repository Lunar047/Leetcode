class Solution {
public:
    int countPrimes(int n) {
        int ans = 0;
        vector<int> is_prime(n+2, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i*i <= n; i++) {
            if (is_prime[i]) {
                // ans++;
                for (int j = i * 2; j <=n; j += i)
                    is_prime[j] = false;
            }
        }
        for(int i=0;i<n;i++)if(is_prime[i])ans++;
        return ans;
    }
};