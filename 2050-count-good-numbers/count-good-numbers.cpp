class Solution {
public:
    int mp(int x, long long n){
        if(n==1) return x;
        if(n==0) return 1;
        long long hf = mp(x,n/2)%1000000007;
        if(n&1){
            return (((hf*hf)%1000000007)*x)%1000000007;
        }
        return (hf*hf)%1000000007;
    }

    int countGoodNumbers(long long n) {
        long long numodd = n/2;
        long long numeven = n-numodd;

        int codd = mp(4, numodd)%1000000007;
        int ceven = mp(5,numeven)%1000000007;

        return ((long long)codd*ceven)%1000000007;
    }
};