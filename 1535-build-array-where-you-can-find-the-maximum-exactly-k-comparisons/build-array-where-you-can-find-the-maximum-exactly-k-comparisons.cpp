class Solution {
public:
    int MOD = 1000000007;
    int N;
    int M;
    int K;
    int memo[51][51][101] ;

    int solve(int i, int len, int maxi){
        if(i==N){
            if(len==K){
                return 1;
            }
            return 0;
        }
        if(memo[i][len][maxi]!=-1){
            return memo[i][len][maxi];
        }

        int result = 0;

        for(int j=1;j<=M;j++){
            if(j > maxi){
                result = (result + solve(i+1, len+1, j))%MOD;
            }else{
                result = (result + solve(i+1, len, maxi))%MOD;

            }
        }

        return memo[i][len][maxi] = result % MOD;
    }

    int numOfArrays(int n, int m, int k) {
        N = n;
        M = m;
        K = k;
        
        memset(memo, -1, sizeof(memo));

        return solve(0, 0, 0);
    }
};