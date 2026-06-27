class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(divisor == dividend) return 1;

        bool neg = (dividend<0) ^ (divisor<0);

        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);

        long long quotient = 0;

        while(n>=d){
            int i = 0;
            
            while(n >= (d << (i+1))){
                i++;
            }
            quotient += (1LL << i);
            n -= (d<<i);
        }
        return neg ? -quotient : quotient;
    }
};