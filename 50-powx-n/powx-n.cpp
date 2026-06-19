class Solution {
public:
    double mp(double x, long long n){
        if(n==0) return 1.0;

        double half = mp(x,n/2);

        if(n%2==0){
            return half*half;
        }
        return half*half*x;
    }

    double myPow(double x, int n) {
        long long N = n;
        if(n<0){
            x = 1/x;
            N = -N;
        }

        return mp(x, N);
    }
};