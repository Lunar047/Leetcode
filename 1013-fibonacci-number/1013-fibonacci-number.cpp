class Solution {
private:
public:
    int fib(int n) {
        // Attept 02
        double t = sqrt(5);
        long long ans =(1/t)*(pow((1+t)/2,n)-pow((1-t)/2,n));
        return ans;
       
    }
};