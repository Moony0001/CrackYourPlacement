class Solution {
public:

    double pow(double x, long long n){
        if(n==0) return 1;
        if(n==1) return x;
        double half = pow(x, n>>1);
        if(n&1){
            return (half*half*x);
        }
        return half*half;
    }

    double myPow(double x, int n) {
        bool neg = 0;
        long long t = n;
        if(n<0){
            neg = 1;
            t = -t;
        } 
        double ans = pow(x, t);
        if(neg){
            ans = 1/ans;
        }
        return ans;
    }
};