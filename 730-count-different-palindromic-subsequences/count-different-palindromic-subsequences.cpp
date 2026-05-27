class Solution {
public:
    int countPalindromicSubsequences(string s) {
        int mod = 1000000007;
        int n = s.size();
        vector<vector<long long>> dp(n, vector<long long>(n,0));

        for(int i=0;i<n;i++){
            dp[i][i] = 1;
        }

        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(s[i]!=s[j]){
                    dp[i][j] = (dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1]+mod)%mod;
                }else{
                    int low = INT_MAX;
                    int high = INT_MIN;
                    int k = i+1;
                    
                    while(k<j){
                        if(s[i]==s[k]){
                            low = k;
                            break;
                        }
                        k++;
                    }

                    k = j-1;
                    while(k>i){
                        if(s[j]==s[k]){
                            high = k;
                            break;
                        }
                        k--;
                    }
                    if(low>high){
                        dp[i][j] = (2*dp[i+1][j-1]+2)%mod;
                    }else if(low==high){
                        dp[i][j] = (2*dp[i+1][j-1]+1)%mod;
                    }else{
                        dp[i][j] = (2*dp[i+1][j-1]-dp[low+1][high-1]+mod)%mod;
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};